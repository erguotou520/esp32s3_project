#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "ui_study.h"
#include "ui_common.h"
#include "page_manager.h"
#include "audio_res.h"
#include "esp32_s3_szp.h"

static lv_obj_t * page;
static int correct_count = 0;
static int total_count = 0;
static lv_obj_t * question_label;
static lv_obj_t * textarea;
static lv_span_t * correct_count_span;
static lv_span_t * incorrect_count_span;
static lv_span_t * total_count_span;

// 设计一个小学加减算出题页面，要求是20以内加减法，有2个数或3个数参与加减，但是所有的数字都不能超出20，上方是一个flex，其左侧显示题目，例如8+()-3=12，右侧是{对的题数}/{错的题数}/{总题数}。接着下方左侧上方是一个textarea，下方是一个OK按钮，右侧是输入键盘，可以输入0-9，还有删除按钮

typedef struct {
    char *expression;
    int answer;
} Expression;

static Expression current_expression;

void generate_random_expression(Expression *expression) {
    char buffer[24];
    int result;

    do {
        int num1 = rand() % 19 + 1;
        int num2 = rand() % 19 + 1;
        int num3 = rand() % 19 + 1;
        char operator1 = (rand() % 2) ? '+' : '-';
        char operator2 = (rand() % 2) ? '+' : '-';

        int missing_index = rand() % 4; // 随机选择一个位置作为问题项

        if (operator1 == '+') {
            result = num1 + num2;
        } else {
            result = num1 - num2;
        }

        if (operator2 == '+') {
            result += num3;
        } else {
            result -= num3;
        }

        if (result >= 0 && result <= 20) {
            if (missing_index == 0) {
                expression->answer = num1;
                snprintf(buffer, sizeof(buffer), "( ) %c %d %c %d = %d", operator1, num2, operator2, num3, result);
            } else if (missing_index == 1) {
                expression->answer = num2;
                snprintf(buffer, sizeof(buffer), "%d %c ( ) %c %d = %d", num1, operator1, operator2, num3, result);
            } else if (missing_index == 2) {
                expression->answer = num3;
                snprintf(buffer, sizeof(buffer), "%d %c %d %c ( ) = %d", num1, operator1, num2, operator2, result);
            } else if (missing_index == 3) {
                expression->answer = result;
                snprintf(buffer, sizeof(buffer), "%d %c %d %c %d = ( )", num1, operator1, num2, operator2, num3);
            }
            expression->expression = strdup(buffer);
            break;
        }
    } while (1);
}

static void btnm_event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_t * ta = lv_event_get_user_data(e);
    const char * txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));

    if(strcmp(txt, LV_SYMBOL_BACKSPACE) == 0) lv_textarea_del_char(ta);
    else if(strcmp(txt, ".") == 0) return;
    else lv_textarea_add_text(ta, txt);
}

static void ok_btn_event_handler(lv_event_t * e) {
    const char * txt = lv_textarea_get_text(textarea);
    // 检查输入是否为空
    if (txt == NULL || strlen(txt) == 0) {
        return;
    }

    int answer = atoi(txt);
    bool is_correct = answer == current_expression.answer;

    char count_str[16];  // 用于转换数字到字符串
    if (is_correct) {
        correct_count++;
        snprintf(count_str, sizeof(count_str), "%d", correct_count);
        lv_span_set_text(correct_count_span, count_str);
    }
    total_count++;
    snprintf(count_str, sizeof(count_str), "%d", total_count);
    lv_span_set_text(total_count_span, count_str);
    if (!is_correct) {
        snprintf(count_str, sizeof(count_str), "%d", total_count - correct_count);
        lv_span_set_text(incorrect_count_span, count_str);
    }

    if (is_correct) {
        play_audio(correct_pcm_start, correct_pcm_end);
    } else {
        play_audio(wrong_pcm_start, wrong_pcm_end);
    }

    // 释放旧的表达式内存
    free(current_expression.expression);

    // 下一题
    generate_random_expression(&current_expression);
    lv_label_set_text(question_label, current_expression.expression);
    lv_textarea_set_text(textarea, "");
}

void lv_study_page(void) {
    srand(time(NULL));
    page = ui_create_common_page(NULL);
    generate_random_expression(&current_expression);

    ui_create_status_bar(page, "计算", &common_header_bg_color);

    // 创建上方的flex容器
    lv_obj_t *flex = lv_obj_create(page);
    lv_obj_set_size(flex, LV_PCT(100), 50);
    lv_obj_set_flex_flow(flex, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_flex_main_place(flex, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
    lv_obj_align(flex, LV_ALIGN_TOP_MID, 0, 40);
    lv_obj_set_style_radius(flex, 0, 0); // 禁用圆角
    lv_obj_set_style_pad_all(flex, 10, 0);
    lv_obj_set_style_border_width(flex, 0, 0);

    // 左侧显示题目
    question_label = lv_label_create(flex);
    lv_label_set_text(question_label, current_expression.expression);
    lv_obj_set_style_text_font(question_label, &lv_font_montserrat_20, 0);
    lv_obj_set_style_text_color(question_label, lv_color_hex(0x000000), 0);

    // 右侧显示{对的题数}/{错的题数}/{总题数}
    lv_obj_t *score_label = lv_spangroup_create(flex);
    char correct_text[5], incorrect_text[5], total_text[5];
    snprintf(correct_text, sizeof(correct_text), "%d", correct_count);
    snprintf(incorrect_text, sizeof(incorrect_text), "%d", total_count - correct_count);
    snprintf(total_text, sizeof(total_text), "%d", total_count);

    correct_count_span = lv_spangroup_new_span(score_label);
    lv_span_set_text(correct_count_span, correct_text);
    lv_style_set_text_color(&correct_count_span->style, lv_color_hex(0x00FF00)); // 绿色

    lv_span_t *slash1_span = lv_spangroup_new_span(score_label);
    lv_span_set_text(slash1_span, "/");
    lv_style_set_text_color(&slash1_span->style, lv_color_hex(0x808080)); // 灰色

    incorrect_count_span = lv_spangroup_new_span(score_label);
    lv_span_set_text(incorrect_count_span, incorrect_text);
    lv_style_set_text_color(&incorrect_count_span->style, lv_color_hex(0xFF0000)); // 红色

    lv_span_t *slash2_span = lv_spangroup_new_span(score_label);
    lv_span_set_text(slash2_span, "/");
    lv_style_set_text_color(&slash2_span->style, lv_color_hex(0x808080)); // 灰色

    total_count_span = lv_spangroup_new_span(score_label);
    lv_span_set_text(total_count_span, total_text);
    lv_style_set_text_color(&total_count_span->style, lv_color_hex(0x000000)); // 黑色
    lv_obj_set_style_text_font(score_label, &lv_font_montserrat_20, 0);
    lv_obj_set_style_text_color(score_label, lv_color_hex(0x000000), 0);

    // 创建下方左侧的textarea
    textarea = lv_textarea_create(page);
    lv_textarea_set_one_line(textarea, true);
    lv_textarea_set_accepted_chars(textarea, "0123456789.");
    lv_obj_set_size(textarea, 60, 40);
    lv_textarea_set_max_length(textarea, 5);
    lv_obj_align(textarea, LV_ALIGN_BOTTOM_LEFT, 10, -60);
    lv_obj_add_state(textarea, LV_STATE_FOCUSED);

    // 创建下方左侧的OK按钮
    lv_obj_t *ok_btn = lv_btn_create(page);
    lv_obj_set_size(ok_btn, 60, 40);
    lv_obj_align(ok_btn, LV_ALIGN_BOTTOM_LEFT, 10, -10);
    lv_obj_t *ok_label = lv_label_create(ok_btn);
    lv_label_set_text(ok_label, "OK");
    lv_obj_center(ok_label);
    lv_obj_add_event_cb(ok_btn, ok_btn_event_handler, LV_EVENT_CLICKED, NULL);

    // 创建右侧的输入键盘
    // lv_obj_t *kb = lv_keyboard_create(page);
    // lv_obj_set_size(kb, 240, 150);
    // lv_obj_align(kb, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    // lv_keyboard_set_mode(kb, LV_KEYBOARD_MODE_NUMBER);
    // lv_keyboard_set_textarea(kb, textarea);

    static const char * btnm_map[] = {"1", "2", "3", ".", "\n",
                                      "4", "5", "6", "0", "\n",
                                      "7", "8", "9", LV_SYMBOL_BACKSPACE, "",
                                     };
    
    lv_obj_t * btnm = lv_btnmatrix_create(page);
    lv_obj_set_size(btnm, 220, 140);
    lv_obj_align(btnm, LV_ALIGN_BOTTOM_RIGHT, -10, -10);
    lv_obj_set_style_pad_all(btnm, 0, 0);
    lv_obj_set_style_border_width(btnm, 0, 0);
    lv_obj_set_style_radius(btnm, 0, 0);
    lv_obj_set_style_pad_row(btnm, 1, 0);
    lv_obj_set_style_pad_column(btnm, 1, 0);
    lv_obj_set_style_radius(btnm, 0, LV_PART_ITEMS);
    // 设置按钮矩阵中每个按钮的样式，不显示阴影
    lv_obj_set_style_shadow_opa(btnm, LV_OPA_TRANSP, LV_PART_ITEMS);
    lv_obj_set_style_shadow_width(btnm, 0, LV_PART_ITEMS);
    lv_obj_set_style_shadow_spread(btnm, 0, LV_PART_ITEMS);
    lv_obj_set_style_shadow_ofs_x(btnm, 0, LV_PART_ITEMS);
    lv_obj_set_style_shadow_ofs_y(btnm, 0, LV_PART_ITEMS);

    lv_obj_add_event_cb(btnm, btnm_event_handler, LV_EVENT_VALUE_CHANGED, textarea);
    // lv_obj_remove_flag(btnm, LV_OBJ_FLAG_CLICK_FOCUSABLE); /*To keep the text area focused on button clicks*/
    lv_btnmatrix_set_map(btnm, btnm_map);
}

void lv_study_page_destroy(void) {
    if (current_expression.expression) {
        free(current_expression.expression);
        current_expression.expression = NULL;
    }
    // 重置所有静态变量
    correct_count = 0;
    total_count = 0;
    question_label = NULL;
    textarea = NULL;
    correct_count_span = NULL;
    incorrect_count_span = NULL;
    total_count_span = NULL;
}

page_register_params_t study_page_register_params = {
    .page_id = PAGE_STUDY,
    .active_cb = lv_study_page,
    .destroy_cb = lv_study_page_destroy
};

void init_study_page(void) {
    page_register(study_page_register_params);
}
