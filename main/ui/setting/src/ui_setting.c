#include "ui_setting.h"
#include "ui_common.h"
#include "page_manager.h"

enum {
    LV_MENU_ITEM_BUILDER_VARIANT_1,
    LV_MENU_ITEM_BUILDER_VARIANT_2
};
typedef uint8_t lv_menu_builder_variant_t;

static void back_event_handler(lv_event_t * e);
lv_obj_t * root_page;
static lv_obj_t * create_text(lv_obj_t * parent, const char * icon, const char * txt,
                              lv_menu_builder_variant_t builder_variant);
static lv_obj_t * create_slider(lv_obj_t * parent,
                                const char * icon, const char * txt, int32_t min, int32_t max, int32_t val);
static lv_obj_t * create_switch(lv_obj_t * parent,
                                const char * icon, const char * txt, bool chk);

void lv_setting_page(void)
{
    lv_obj_t * menu = lv_menu_create(lv_scr_act());
    lv_obj_set_style_radius(menu, 10, 0);
    lv_obj_t * back_btn = lv_menu_get_main_header_back_btn(menu);
    lv_obj_set_size(back_btn, 40, 40);
    lv_obj_t * header = lv_menu_get_main_header(menu);
    // 获取标题标签对象（通常是header的第二个子对象，因为第一个是返回按钮）
    lv_obj_t * title = lv_obj_get_child(header, 1);
    if(title) {
        // 设置字体大小
        lv_obj_set_style_text_font(title, &font_alipuhui20, 0);  // 使用20号中文字体
        
        // 设置文字颜色
        lv_obj_set_style_text_color(title, lv_color_hex(0x000000), 0);
        
        // 设置文字对齐方式
        lv_obj_set_style_text_align(title, LV_TEXT_ALIGN_CENTER, 0);
        
        // 调整标题位置
        lv_obj_align(title, LV_ALIGN_CENTER, 0, 0);
    }

    lv_color_t bg_color = lv_obj_get_style_bg_color(menu, 0);
    if(lv_color_brightness(bg_color) > 127) {
        lv_obj_set_style_bg_color(menu, lv_color_darken(lv_obj_get_style_bg_color(menu, 0), 10), 0);
    }
    else {
        lv_obj_set_style_bg_color(menu, lv_color_darken(lv_obj_get_style_bg_color(menu, 0), 50), 0);
    }
    lv_menu_set_mode_root_back_btn(menu, LV_MENU_ROOT_BACK_BTN_ENABLED);
    lv_obj_add_event_cb(menu, back_event_handler, LV_EVENT_CLICKED, menu);
    lv_obj_set_size(menu, LV_HOR_RES, LV_VER_RES);
    lv_obj_center(menu);

    lv_obj_t * cont;
    lv_obj_t * section;

    // 创建子页面
    lv_obj_t * sub_wifi_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(sub_wifi_page, 0, 0);
    lv_menu_separator_create(sub_wifi_page);
    section = lv_menu_section_create(sub_wifi_page);
    create_switch(section,  NULL, "启用 WIFI", true);

    lv_obj_t * sub_ble_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(sub_ble_page, 0, 0);
    lv_menu_separator_create(sub_ble_page);
    section = lv_menu_section_create(sub_ble_page);
    create_switch(section, NULL, "启用蓝牙", false);

    lv_obj_t * sub_display_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(sub_display_page, 0, 0);
    lv_menu_separator_create(sub_display_page);
    section = lv_menu_section_create(sub_display_page);
    create_switch(section, NULL, "开启背光", false);

    lv_obj_t * sub_about_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(sub_about_page, 0, 0);
    section = lv_menu_section_create(sub_about_page);
    create_text(section, NULL, "Version 1.0", LV_MENU_ITEM_BUILDER_VARIANT_1);

    // 创建主页面
    root_page = lv_menu_page_create(menu, "设置");
    lv_obj_set_style_pad_hor(root_page, 0, 0);
    lv_obj_set_size(root_page, 120, LV_VER_RES);
    section = lv_menu_section_create(root_page);
    cont = create_text(section, NULL, "WIFI", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, sub_wifi_page);
    cont = create_text(section, NULL, "蓝牙", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, sub_ble_page);
    cont = create_text(section, NULL, "背光", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, sub_display_page);
    cont = create_text(section, NULL, "关于", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, sub_about_page);

    lv_menu_set_sidebar_page(menu, root_page);

    lv_event_send(lv_obj_get_child(lv_obj_get_child(lv_menu_get_cur_sidebar_page(menu), 0), 0), LV_EVENT_CLICKED, NULL);
}

static void back_event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_t * menu = lv_event_get_user_data(e);

    if(lv_menu_back_btn_is_root(menu, obj)) {
        navigate_back();
    }
}

static lv_obj_t * create_text(lv_obj_t * parent, const char * icon, const char * txt,
                              lv_menu_builder_variant_t builder_variant)
{
    lv_obj_t * obj = lv_menu_cont_create(parent);

    lv_obj_t * img = NULL;
    lv_obj_t * label = NULL;

    if(icon) {
        img = lv_img_create(obj);
        lv_img_set_src(img, icon);
    }

    if(txt) {
        label = lv_label_create(obj);
        lv_label_set_text(label, txt);
        lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_flex_grow(label, 1);
    }

    if(builder_variant == LV_MENU_ITEM_BUILDER_VARIANT_2 && icon && txt) {
        lv_obj_add_flag(img, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
        lv_obj_swap(img, label);
    }

    return obj;
}

static lv_obj_t * create_slider(lv_obj_t * parent, const char * icon, const char * txt, int32_t min, int32_t max,
                                int32_t val)
{
    lv_obj_t * obj = create_text(parent, icon, txt, LV_MENU_ITEM_BUILDER_VARIANT_2);

    lv_obj_t * slider = lv_slider_create(obj);
    lv_obj_set_flex_grow(slider, 1);
    lv_slider_set_range(slider, min, max);
    lv_slider_set_value(slider, val, LV_ANIM_OFF);

    if(icon == NULL) {
        lv_obj_add_flag(slider, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
    }

    return obj;
}

static lv_obj_t * create_switch(lv_obj_t * parent, const char * icon, const char * txt, bool chk)
{
    lv_obj_t * obj = create_text(parent, icon, txt, LV_MENU_ITEM_BUILDER_VARIANT_1);

    lv_obj_t * sw = lv_switch_create(obj);
    lv_obj_add_state(sw, chk ? LV_STATE_CHECKED : 0);

    return obj;
}

page_register_params_t setting_page_register_params = {
    .page_id = PAGE_SETTING,
    .active_cb = lv_setting_page,
    .destroy_cb = NULL
};

void init_setting_page(void) {
    page_register(setting_page_register_params);
}