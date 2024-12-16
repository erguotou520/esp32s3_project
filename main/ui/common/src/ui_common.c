#include "ui_common.h"
#include "lvgl.h"
#include "page_manager.h"

lv_color_t common_header_bg_color = LV_COLOR_MAKE(0x30, 0xa8, 0x30);

void _navigate_back(lv_event_t *e) {
    navigate_back();
}

void ui_create_back_btn(lv_obj_t *parent) {
    // 创建后退按钮
    lv_obj_t *back_btn = lv_btn_create(parent);
    lv_obj_align(back_btn, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_size(back_btn, 40, 40);
    lv_obj_set_style_border_width(back_btn, 0, 0); // 设置边框宽度
    lv_obj_set_style_pad_all(back_btn, 0, 0);  // 设置间隙
    lv_obj_set_style_bg_opa(back_btn, LV_OPA_TRANSP, LV_PART_MAIN); // 背景透明
    lv_obj_set_style_shadow_opa(back_btn, LV_OPA_TRANSP, LV_PART_MAIN); // 阴影透明
    lv_obj_add_event_cb(back_btn, _navigate_back, LV_EVENT_CLICKED, NULL); // 事件处理

    // 创建后退图标
    lv_obj_t *label_back = lv_label_create(back_btn); 
    lv_label_set_text(label_back, LV_SYMBOL_LEFT);  // 按键上显示左箭头符号
    lv_obj_set_style_text_font(label_back, &lv_font_montserrat_20, 0);
    lv_obj_set_style_text_color(label_back, lv_color_hex(0xffffff), 0); 
    lv_obj_align(label_back, LV_ALIGN_CENTER, 0, 0);
}

// 创建顶部状态栏
void ui_create_status_bar(lv_obj_t *parent, const char *title, lv_color_t bg_color) {

    lv_obj_t *status_bar = lv_obj_create(parent);
    lv_obj_set_size(status_bar, LV_HOR_RES, 40);
    lv_obj_set_style_pad_all(status_bar, 0, 0);  // 设置间隙
    lv_obj_align(status_bar, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_set_style_border_width(status_bar, 0, 0);
    // 设置左上和右上圆角
    lv_obj_set_style_radius(status_bar, 10, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(status_bar, bg_color, 0); // 设置背景颜色

    // 显示居中标题
    lv_obj_t *label = lv_label_create(status_bar);
    lv_label_set_text(label, title);
    lv_obj_set_style_text_color(label, lv_color_hex(0xffffff), 0); 
    // lv_obj_set_style_text_font(label, &lv_font_montserrat_20, 0);
    lv_obj_set_style_text_font(label, &font_alipuhui20, 0);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    // 创建后退按钮
    ui_create_back_btn(status_bar);
}


// 创建通用页面
lv_obj_t *ui_create_common_page(lv_color_t *bg_color) {
    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_radius(&style, 10);
    lv_style_set_bg_opa( &style, LV_OPA_COVER );
    
    if (bg_color != NULL) {
        lv_style_set_bg_color(&style, *bg_color);
    } else {
        lv_style_set_bg_color(&style, lv_color_hex(0xffffff));
    }
    lv_style_set_border_width(&style, 0);
    lv_style_set_pad_all(&style, 0);
    lv_style_set_width(&style, LV_HOR_RES);  
    lv_style_set_height(&style, LV_VER_RES); 

    lv_obj_t *page = lv_obj_create(lv_scr_act());
    lv_obj_add_style(page, &style, 0);
    return page;
}