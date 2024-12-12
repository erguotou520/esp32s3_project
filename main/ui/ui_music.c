#include "ui_music.h"
#include "ui_common.h"

static lv_obj_t * page;
static lv_obj_t * label;

void lv_music_page() {
    page = lv_obj_create(lv_scr_act());
    lv_obj_set_size(page, LV_HOR_RES, LV_VER_RES);

    label = lv_label_create(page);
    lv_label_set_text(label, "这是音乐页面");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

