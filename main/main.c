#include <stdio.h>
#include "ui_main.h"
#include "page_manager.h"
#include "esp32_s3_szp.h"
#include "nvs_flash.h"
#include <esp_system.h>


// 主函数
void app_main(void)
{
    // Initialize NVS.
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK( ret );

    bsp_i2c_init();  // I2C初始化
    pca9557_init();  // IO扩展芯片初始化
    bsp_lvgl_start(); // 初始化液晶屏lvgl接口
    bsp_spiffs_mount(); // SPIFFS文件系统初始化
    bsp_codec_init(); // 音频初始化
    page_manager_init(); // 页面管理器初始化
    init_pages(); // 主页面初始化
    // lv_gui_start(); // 显示开机界面
    // xTaskCreatePinnedToCore(main_page_task, "main_page_task", 4*1024, NULL, 5, NULL, 0); // 主界面任务

    // while (true) {
    //     vTaskDelay(pdMS_TO_TICKS(5 * 1000));
    // }
}
