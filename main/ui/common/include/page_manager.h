#ifndef PAGE_MANAGER_H
#define PAGE_MANAGER_H

typedef void (*page_active_cb_t)(void);
typedef void (*page_destroy_cb_t)(void);

typedef struct {
    page_active_cb_t active;
    page_destroy_cb_t destroy;
} page_t;


typedef enum {
    PAGE_MAIN,
    PAGE_ALBUM,
    PAGE_CAMERA,
    PAGE_MUSIC,
    PAGE_PLAY,
    PAGE_RECORD,
    PAGE_SETTING,
    PAGE_STUDY,
    PAGE_WEATHER,
    PAGE_MAX
} page_id_t;

typedef struct {
    page_id_t page_id;
    page_active_cb_t active_cb;
    page_destroy_cb_t destroy_cb;
} page_register_params_t;

void page_manager_init(void);

bool page_register(page_register_params_t params);

page_id_t get_current_page(void);

bool navigate_to(page_id_t page_id);

void navigate_back(void);

#endif