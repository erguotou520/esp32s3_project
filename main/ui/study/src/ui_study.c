#include "ui_study.h"
#include "ui_common.h"
#include "page_manager.h"

static lv_obj_t * page;
static lv_obj_t * label;

void lv_study_page(void) {
    page = ui_create_common_page(NULL);

    ui_create_status_bar(page, "学习", &common_header_bg_color);

    label = lv_label_create(page);
    lv_obj_set_style_text_font(label, &font_alipuhui20, 0);
    lv_label_set_text(label, "这是学习页面");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

page_register_params_t study_page_register_params = {
    .page_id = PAGE_STUDY,
    .active_cb = lv_study_page,
    .destroy_cb = NULL
};

void init_study_page(void) {
    page_register(study_page_register_params);
}
