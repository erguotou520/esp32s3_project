#ifndef UI_COMMON_H
#define UI_COMMON_H

#include "lvgl.h"

// 声明字体
LV_FONT_DECLARE(font_alipuhui20);
LV_FONT_DECLARE(font_icon44);

// 共用的颜色
extern lv_color_t common_header_bg_color;

// 创建通用页面
lv_obj_t *ui_create_common_page(lv_color_t *bg_color);

// 创建后退按钮
void ui_create_back_btn(lv_obj_t *parent);

// 创建顶部状态栏
void ui_create_status_bar(lv_obj_t *parent, const char *title, lv_color_t bg_color);

#endif