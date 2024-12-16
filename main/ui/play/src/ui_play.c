#include "ui_play.h"
#include "ui_common.h"
#include "page_manager.h"

static lv_obj_t * page;
static lv_obj_t * label;

void lv_play_page(void) {
    page = ui_create_common_page(NULL);

    ui_create_status_bar(page, "娱乐", common_header_bg_color);

    label = lv_label_create(page);
    lv_obj_set_style_text_font(label, &font_alipuhui20, 0);
    lv_label_set_text(label, "这是娱乐页面");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

page_register_params_t play_page_register_params = {
    .page_id = PAGE_PLAY,
    .active_cb = lv_play_page,
    .destroy_cb = NULL
};

void init_play_page(void) {
    page_register(play_page_register_params);
}