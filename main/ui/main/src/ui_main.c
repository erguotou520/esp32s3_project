#include "ui_main.h"
#include "ui_common.h"
#include "ui_study.h"
#include "ui_play.h"
#include "ui_weather.h"
#include "ui_camera.h"
#include "ui_album.h"
#include "ui_music.h"
#include "ui_record.h"
#include "ui_setting.h"
#include "page_manager.h"
#include "esp32_s3_szp.h"


// 创建应用图标函数
static lv_obj_t* create_app_icon(lv_obj_t *parent, lv_style_t *style,
                                int x, int y,
                                lv_color_t color, 
                                lv_event_cb_t event_cb,
                                const char *icon_text) {
    // 创建图标按钮
    lv_obj_t *icon = lv_btn_create(parent);
    lv_obj_add_style(icon, style, 0);
    lv_obj_set_style_bg_color(icon, color, 0);
    lv_obj_set_pos(icon, x, y);
    lv_obj_add_event_cb(icon, event_cb, LV_EVENT_CLICKED, NULL);

    // 使用文字
    lv_obj_t *lbl = lv_label_create(icon);
    lv_obj_set_style_text_font(lbl, &font_icon44, 0);
    lv_label_set_text(lbl, icon_text);
    lv_obj_align(lbl, LV_ALIGN_CENTER, 0, 0);

    return icon;
}

// 页面跳转函数
void navigate_to_page1(lv_event_t * e)
{
    navigate_to(PAGE_STUDY);
}

void navigate_to_page2(lv_event_t * e)
{
    navigate_to(PAGE_PLAY);
}

void navigate_to_page3(lv_event_t * e)
{
    navigate_to(PAGE_WEATHER);
}

void navigate_to_page4(lv_event_t * e)
{
    navigate_to(PAGE_CAMERA);
}

void navigate_to_page5(lv_event_t * e)
{
    navigate_to(PAGE_ALBUM);
}

void navigate_to_page6(lv_event_t * e)
{
    navigate_to(PAGE_RECORD);
}

void navigate_to_page7(lv_event_t * e)
{
    navigate_to(PAGE_MUSIC);
}

void navigate_to_page8(lv_event_t * e)
{
    navigate_to(PAGE_SETTING);
}

// 主界面
void lv_main_page(void)
{
    lvgl_port_lock(0);

    // 创建主界面基本对象
    lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0x000000), 0); // 修改背景为黑色

    static lv_style_t bg_style;
    lv_style_init(&bg_style);
    lv_style_set_radius(&bg_style, 10);  
    lv_style_set_bg_opa(&bg_style, LV_OPA_COVER);
    lv_style_set_bg_color(&bg_style, lv_color_hex(0x00BFFF));
    lv_style_set_bg_grad_color(&bg_style, lv_color_hex(0x00BF00));
    lv_style_set_bg_grad_dir(&bg_style, LV_GRAD_DIR_VER);
    lv_style_set_border_width(&bg_style, 0);
    lv_style_set_pad_all(&bg_style, 0);
    lv_style_set_width(&bg_style, 320);  
    lv_style_set_height(&bg_style, 240); 

    lv_obj_t *main_obj = lv_obj_create(lv_scr_act());
    lv_obj_add_style(main_obj, &bg_style, 0);

    // 显示左上角欢迎语
    lv_obj_t *main_text_label = lv_label_create(main_obj);
    lv_obj_set_style_text_font(main_text_label, &font_alipuhui20, 0);
    lv_label_set_long_mode(main_text_label, LV_LABEL_LONG_SCROLL_CIRCULAR);     /*Circular scroll*/
    lv_obj_set_width(main_text_label, 280);
    lv_label_set_text(main_text_label, "和沐学习娱乐机");
    lv_obj_align_to(main_text_label, main_obj, LV_ALIGN_TOP_LEFT, 8, 5);

    // 显示右上角符号
    lv_obj_t *sylbom_label = lv_label_create(main_obj);
    lv_obj_set_style_text_font(sylbom_label, &lv_font_montserrat_20, 0);
    lv_obj_set_style_text_color(sylbom_label, lv_color_hex(0xffffff), 0);
    lv_label_set_text(sylbom_label, LV_SYMBOL_BLUETOOTH" "LV_SYMBOL_WIFI);  // 显示蓝牙和wifi图标
    lv_obj_align_to(sylbom_label, main_obj, LV_ALIGN_TOP_RIGHT, -10, 10);

    // 创建一个滚动视图来容纳应用图标
    lv_obj_t *scroll_view = lv_obj_create(main_obj);
    lv_obj_set_style_bg_opa(scroll_view, LV_OPA_TRANSP, 0); // 设置背景色为透明
    lv_obj_set_size(scroll_view, 320, 200); // 调整高度以剪掉上面部分的高度
    lv_obj_set_style_pad_hor(scroll_view, 15, 0);  // 设置左右padding
    lv_obj_set_style_pad_ver(scroll_view, 10, 0);  // 设置上下padding
    lv_obj_set_style_border_width(scroll_view, 0, 0);
    lv_obj_set_scrollbar_mode(scroll_view, LV_SCROLLBAR_MODE_OFF); // 不显示滚动条
    lv_obj_set_scroll_dir(scroll_view, LV_DIR_VER); // 仅垂直滚动
    lv_obj_align(scroll_view, LV_ALIGN_TOP_MID, 0, 40); // 将滚动视图放置在下方

    // 设置应用图标style
    static lv_style_t btn_style;
    lv_style_init(&btn_style);
    lv_style_set_radius(&btn_style, 16);  
    lv_style_set_bg_opa(&btn_style, LV_OPA_COVER);
    lv_style_set_text_color(&btn_style, lv_color_hex(0xffffff)); 
    lv_style_set_border_width(&btn_style, 0);
    lv_style_set_pad_all(&btn_style, 5);
    lv_style_set_width(&btn_style, 80);  
    lv_style_set_height(&btn_style, 80); 

    // 学习
    create_app_icon(scroll_view, &btn_style, 0, 0, lv_color_hex(0x30a830), navigate_to_page1, "\xee\xa1\x92");
    // 娱乐
    create_app_icon(scroll_view, &btn_style, 105, 0, lv_color_hex(0xf87c30), navigate_to_page2, "\xee\x99\x80");
    // 天气
    create_app_icon(scroll_view, &btn_style, 210, 0, lv_color_hex(0x008b8b), navigate_to_page3, "\xee\xa3\x88");
    // 拍照
    create_app_icon(scroll_view, &btn_style, 0, 97, lv_color_hex(0xd8b010), navigate_to_page4, "\xee\x99\xad");
    // 相册
    create_app_icon(scroll_view, &btn_style, 105, 97, lv_color_hex(0xcd5c5c), navigate_to_page5, "\xee\x9b\xb8");
    // 录音
    create_app_icon(scroll_view, &btn_style, 210, 97, lv_color_hex(0xb87fa8), navigate_to_page6, "\xee\x9b\x83");
    // 音乐
    create_app_icon(scroll_view, &btn_style, 0, 192, lv_color_hex(0xEB8258), navigate_to_page7, "\xee\x9e\x95");
    // 设置
    create_app_icon(scroll_view, &btn_style, 105, 192, lv_color_hex(0x81BFDA), navigate_to_page8, "\xee\xa5\xa6");
    
    lvgl_port_unlock();
}

page_register_params_t main_page_register_params = {
    .page_id = PAGE_MAIN,
    .active_cb = lv_main_page,
    .destroy_cb = NULL
};


void init_pages(void) {
    page_register(main_page_register_params);
    init_album_page();
    init_camera_page();
    init_music_page();
    init_play_page();
    init_record_page();
    init_setting_page();
    init_study_page();
    init_weather_page();

    navigate_to(PAGE_MAIN);
}