#ifndef UI_COMMON_H
#define UI_COMMON_H

#include "lvgl.h"

// 声明字体
LV_FONT_DECLARE(font_alipuhui20);
LV_FONT_DECLARE(font_icon44);

// 共用的样式
// typedef struct {
//     lv_style_t btn_style;
//     lv_style_t bg_style;
// } ui_styles_t;

// 共用的状态变量
extern int page_flag;
// extern lv_obj_t *lckfb_logo;

// 初始化共用样式
// void ui_init_styles(void);

// 创建顶部状态栏
void ui_create_status_bar(lv_obj_t *parent, const char *title, lv_event_cb_t back_cb);

#endif