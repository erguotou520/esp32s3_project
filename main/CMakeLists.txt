# 收集 ui/src 目录下所有 .c 文件
file(GLOB UI_SRC_SOURCES "ui/*.c")

idf_component_register(SRCS "esp32_s3_szp.c" "main.c"
                       SRCS "assets/image_lckfb_logo.c"
                       SRCS "assets/img_att_icon.c"
                       SRCS "assets/img_btset_icon.c"
                       SRCS "assets/img_camera_icon.c"
                       SRCS "assets/img_music_icon.c"
                       SRCS "assets/img_sd_icon.c"
                       SRCS "assets/img_wifiset_icon.c"
                       SRCS "assets/font_alipuhui20.c"
                       SRCS "assets/font_icon44.c"
                       SRCS "bt/ble_hidd_demo.c" "bt/esp_hidd_prf_api.c" "bt/hid_dev.c" "bt/hid_device_le_prf.c"
                       SRCS ${UI_SRC_SOURCES}
                       EMBED_FILES "sword.pcm"
                       INCLUDE_DIRS "."
                       INCLUDE_DIRS "bt"
                       INCLUDE_DIRS "ui")

spiffs_create_partition_image(storage ../spiffs FLASH_IN_PROJECT)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-unused-const-variable)
