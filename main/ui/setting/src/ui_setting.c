#include "ui_setting.h"
#include "ui_common.h"
#include "page_manager.h"

static lv_obj_t * page;
static lv_obj_t * label;

void lv_setting_page(void) {
    page = ui_create_common_page(NULL);

    ui_create_status_bar(page, "设置", &common_header_bg_color);

    label = lv_label_create(page);
    lv_obj_set_style_text_font(label, &font_alipuhui20, 0);
    lv_label_set_text(label, "这是设置页面");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

page_register_params_t setting_page_register_params = {
    .page_id = PAGE_SETTING,
    .active_cb = lv_setting_page,
    .destroy_cb = NULL
};

void init_setting_page(void) {
    page_register(setting_page_register_params);
}
