#ifndef AUDIO_RES_H
#define AUDIO_RES_H

#include <stdint.h>

// 声明外部音频数据
extern const uint8_t correct_pcm_start[] asm("_binary_correct_pcm_start");
extern const uint8_t correct_pcm_end[] asm("_binary_correct_pcm_end");
extern const uint8_t wrong_pcm_start[] asm("_binary_wrong_pcm_start");
extern const uint8_t wrong_pcm_end[] asm("_binary_wrong_pcm_end");

#endif