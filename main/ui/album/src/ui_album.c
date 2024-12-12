#include "ui_album.h"
#include "ui_common.h"
#include "page_manager.h"

static lv_obj_t * page;
static lv_obj_t * label;

void lv_album_page(void) {
    page = ui_create_common_page(NULL);

    ui_create_status_bar(page, "相册", &common_header_bg_color);

    label = lv_label_create(page);
    lv_obj_set_style_text_font(label, &font_alipuhui20, 0);
    lv_label_set_text(label, "这是相册页面");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

page_register_params_t album_page_register_params = {
    .page_id = PAGE_ALBUM,
    .active_cb = lv_album_page,
    .destroy_cb = NULL
};

void init_album_page(void) {
    page_register(album_page_register_params);
}
