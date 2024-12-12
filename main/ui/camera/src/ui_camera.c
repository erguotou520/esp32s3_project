#include "ui_camera.h"
#include "ui_common.h"
#include "page_manager.h"

static lv_obj_t * page;
static lv_obj_t * label;

void lv_camera_page(void) {
    lv_color_t bg_color = lv_color_hex(0x000000);
    page = ui_create_common_page(&bg_color);

    ui_create_status_bar(page, NULL, NULL);

    label = lv_label_create(page);
    lv_obj_set_style_text_font(label, &font_alipuhui20, 0);
    lv_label_set_text(label, "这是相机页面");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

page_register_params_t camera_page_register_params = {
    .page_id = PAGE_CAMERA,
    .active_cb = lv_camera_page,
    .destroy_cb = NULL
};

void init_camera_page(void) {
    page_register(camera_page_register_params);
}
