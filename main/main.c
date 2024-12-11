#include <stdio.h>
#include "esp32_s3_szp.h"
#include "app_ui.h"
#include "nvs_flash.h"
#include <esp_system.h>



// 主界面 任务函数
static void main_page_task()
{
    // 进入主界面
    lv_main_page();

    vTaskDelete(NULL);
}

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

    lv_gui_start(); // 显示开机界面
    main_page_task();
    // xTaskCreatePinnedToCore(main_page_task, "main_page_task", 4*1024, NULL, 5, NULL, 0); // 主界面任务

    // while (true) {
    //     vTaskDelay(pdMS_TO_TICKS(5 * 1000));
    // }
}
