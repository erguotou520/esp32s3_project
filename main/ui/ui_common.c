#include "ui_common.h"
#include "lvgl.h"

int page_flag = 0;

// 创建顶部状态栏
void ui_create_status_bar(lv_obj_t *parent, const char *title, lv_event_cb_t back_cb) {
    lv_obj_t *status_bar = lv_obj_create(parent);
    lv_obj_set_size(status_bar, LV_HOR_RES, 40);
    lv_obj_align(status_bar, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_t *label = lv_label_create(status_bar);
    lv_label_set_text(label, title);
}
