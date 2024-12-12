#include "ui_weather.h"
#include "ui_common.h"
#include "page_manager.h"

static lv_obj_t * page;
static lv_obj_t * label;

void lv_weather_page(void) {
    page = ui_create_common_page(NULL);

    ui_create_status_bar(page, "天气", &common_header_bg_color);

    label = lv_label_create(page);
    lv_obj_set_style_text_font(label, &font_alipuhui20, 0);
    lv_label_set_text(label, "这是天气页面");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

page_register_params_t weather_page_register_params = {
    .page_id = PAGE_WEATHER,
    .active_cb = lv_weather_page,
    .destroy_cb = NULL
};

void init_weather_page(void) {
    page_register(weather_page_register_params);
}
