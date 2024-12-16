#include "lvgl.h"
#include "ui_common.h"
#include <stdlib.h>
#include "page_manager.h"



static page_t pages[PAGE_MAX];

// 页面栈结构
typedef struct page_stack_node {
    page_id_t page_id;
    struct page_stack_node *next;
} page_stack_node_t;

static page_stack_node_t *page_stack = NULL;

bool page_register(page_register_params_t params) {
    if (params.page_id >= PAGE_MAX || params.active_cb == NULL) {
        return false;
    }
    pages[params.page_id].active = params.active_cb;
    pages[params.page_id].destroy = params.destroy_cb;
    return true;
}

bool push_page(page_id_t page_id) {
    page_stack_node_t *new_node = (page_stack_node_t *)malloc(sizeof(page_stack_node_t));
    if (new_node == NULL) {
        return false;  // 内存分配失败
    }
    new_node->page_id = page_id;
    new_node->next = page_stack;
    page_stack = new_node;
    return true;
}

void page_manager_init(void) {
    memset(pages, 0, sizeof(pages));
    page_stack = NULL;
}

void pop_page(void) {
    if (page_stack != NULL) {
        page_stack_node_t *temp = page_stack;
        page_stack = page_stack->next;
        free(temp);
    }
}

page_id_t get_current_page() {
    return page_stack ? page_stack->page_id : PAGE_MAX;
}

bool navigate_to(page_id_t page_id) {
    if (page_id >= PAGE_MAX || pages[page_id].active == NULL) {
        return false;
    }
    
    // page_id_t old_page_id = get_current_page();
    
    if (!push_page(page_id)) {
        return false;
    }
    
    if (page_stack->next != NULL && pages[page_stack->next->page_id].destroy != NULL) {
        pages[page_stack->next->page_id].destroy();
    }
    
    pages[page_id].active();
    
    return true;
}

void navigate_back(void) {
    if (page_stack != NULL) {
        page_id_t current_page = get_current_page();
        if (pages[current_page].destroy != NULL) {
            pages[current_page].destroy();
        }
        pop_page();
        if (page_stack != NULL) {
            pages[page_stack->page_id].active();
        }
    }
}
