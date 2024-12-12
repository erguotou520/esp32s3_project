#include "ui_play.h"
#include "ui_common.h"

static lv_obj_t * page;
static lv_obj_t * label;

void lv_play_page(void) {
    page = lv_obj_create(lv_scr_act());
    lv_obj_set_size(page, LV_HOR_RES, LV_VER_RES);

    label = lv_label_create(page);
    lv_label_set_text(label, "这是娱乐页面");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

