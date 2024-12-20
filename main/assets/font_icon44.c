/*******************************************************************************
 * Size: 44 px
 * Bpp: 1
 * Opts: --bpp 1 --size 44 --no-compress --font iconfont.woff --range 59592,59285,58944,59128,58989,59075,59750,59474 --format lvgl -o font_icon44.c
 ******************************************************************************/

#include "lvgl.h"

#ifndef FONT_ICON44
#define FONT_ICON44 1
#endif

#if FONT_ICON44

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+E640 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe,
    0x0, 0x0, 0x0, 0x0, 0x7, 0x0, 0x0, 0x0,
    0x0, 0x3, 0x80, 0x0, 0x0, 0x0, 0x1, 0xc0,
    0x0, 0x0, 0x0, 0x0, 0xe0, 0x0, 0x0, 0x1,
    0xff, 0xff, 0xf8, 0x0, 0x3, 0xff, 0xff, 0xff,
    0x80, 0x7, 0xff, 0xff, 0xff, 0xf0, 0x7, 0xe0,
    0x0, 0x0, 0xfc, 0x7, 0xc0, 0x0, 0x0, 0x1f,
    0x7, 0xc0, 0x0, 0x0, 0x7, 0xc3, 0xc0, 0x0,
    0x1, 0xc1, 0xe3, 0xc0, 0xe0, 0x0, 0xe0, 0x79,
    0xe0, 0x70, 0x0, 0x70, 0x3d, 0xe0, 0x38, 0x0,
    0x0, 0xf, 0xf0, 0x1c, 0x0, 0x0, 0x7, 0xf8,
    0xff, 0xe0, 0xc0, 0x63, 0xfc, 0x7f, 0xf0, 0xf0,
    0x79, 0xfe, 0x3f, 0xf8, 0x30, 0x18, 0xff, 0x1,
    0xc0, 0x0, 0x0, 0x7f, 0x80, 0xe0, 0x0, 0x0,
    0x3f, 0xc0, 0x70, 0x0, 0x70, 0x1f, 0xe0, 0x38,
    0x0, 0x38, 0xf, 0xf0, 0x0, 0x0, 0x1c, 0x7,
    0xf8, 0x0, 0x0, 0x0, 0x3, 0xfc, 0x0, 0x1f,
    0xc0, 0x1, 0xfe, 0x0, 0x3f, 0xf8, 0x0, 0xff,
    0x0, 0x3f, 0xfe, 0x0, 0x7f, 0x80, 0x3e, 0x7,
    0x0, 0x3f, 0xc0, 0x1e, 0x3, 0xc0, 0x1f, 0xe0,
    0x1e, 0x0, 0xf0, 0xf, 0xf0, 0x1e, 0x0, 0x3c,
    0x7, 0xf8, 0x1f, 0x0, 0xf, 0x3, 0xdf, 0xff,
    0x0, 0x7, 0xff, 0xef, 0xff, 0x0, 0x1, 0xff,
    0xe1, 0xfe, 0x0, 0x0, 0x3f, 0xc0,

    /* U+E66D "" */
    0x3f, 0xff, 0xff, 0xf8, 0x0, 0xff, 0xff, 0xff,
    0xf0, 0x3, 0xff, 0xff, 0xff, 0xe0, 0x7, 0x0,
    0x0, 0x0, 0x0, 0x7e, 0x0, 0x0, 0x0, 0x3,
    0xfc, 0x0, 0x0, 0x0, 0xf, 0xf8, 0xf0, 0x0,
    0x0, 0x7f, 0xf3, 0xf0, 0x0, 0x3, 0xf7, 0xe7,
    0xe0, 0x0, 0x7, 0x8f, 0xcf, 0xc0, 0x0, 0xe,
    0x1f, 0x8f, 0x0, 0x0, 0x1c, 0x3f, 0x0, 0x0,
    0x0, 0x38, 0x7e, 0x0, 0x0, 0x0, 0x70, 0xfc,
    0x0, 0x0, 0x0, 0xe1, 0xf8, 0x0, 0x0, 0x1,
    0xc3, 0xf0, 0x0, 0x0, 0x3, 0x87, 0xe0, 0x0,
    0x0, 0x7, 0xf, 0xc0, 0x0, 0x0, 0xe, 0x1f,
    0x80, 0x0, 0x0, 0x1e, 0x3f, 0x0, 0x0, 0x0,
    0x3e, 0x7e, 0x0, 0x0, 0x0, 0x7f, 0xfc, 0x0,
    0x0, 0x0, 0xef, 0xf8, 0x0, 0x0, 0x1, 0xc7,
    0xf0, 0x0, 0x0, 0x3, 0x87, 0xff, 0xff, 0xff,
    0xff, 0x0, 0xff, 0xff, 0xff, 0xfc, 0x0, 0xff,
    0xff, 0xff, 0xf0, 0x0,

    /* U+E6C3 "" */
    0x0, 0x3, 0xf0, 0x0, 0x0, 0x3, 0xff, 0x0,
    0x0, 0x3, 0xff, 0xf0, 0x0, 0x1, 0xf8, 0x7e,
    0x0, 0x0, 0x78, 0x7, 0x80, 0x0, 0x3c, 0x0,
    0xf0, 0x0, 0xf, 0x0, 0x3c, 0x0, 0x7, 0x80,
    0x7, 0x80, 0x1, 0xe0, 0x1, 0xe0, 0x0, 0x78,
    0x0, 0x78, 0x0, 0x1e, 0x0, 0x1e, 0x0, 0x7,
    0x80, 0x7, 0x80, 0x1, 0xe0, 0x1, 0xe0, 0x0,
    0x78, 0x0, 0x78, 0x0, 0x1e, 0x0, 0x1e, 0x0,
    0x7, 0x80, 0x7, 0x80, 0x1, 0xe0, 0x1, 0xe0,
    0x0, 0x78, 0x0, 0x78, 0x0, 0x1e, 0x0, 0x1e,
    0x0, 0x7, 0x80, 0x7, 0x80, 0x60, 0xf0, 0x3,
    0xc1, 0xbc, 0x3c, 0x0, 0xf0, 0xff, 0x7, 0x80,
    0x78, 0x3f, 0xc1, 0xf8, 0x7e, 0xf, 0xf8, 0x3f,
    0xff, 0x7, 0x9e, 0x3, 0xff, 0x1, 0xe7, 0xc0,
    0x3f, 0x0, 0xf8, 0xf8, 0x0, 0x0, 0x7c, 0x1f,
    0x0, 0x0, 0x3e, 0x7, 0xf0, 0x0, 0x3f, 0x80,
    0xff, 0x0, 0x3f, 0xc0, 0xf, 0xff, 0xff, 0xc0,
    0x1, 0xff, 0xff, 0xc0, 0x0, 0xf, 0xff, 0xc0,
    0x0, 0x0, 0x1e, 0x0, 0x0, 0x0, 0x7, 0x80,
    0x0, 0x0, 0x1, 0xe0, 0x0, 0x0, 0x0, 0x78,
    0x0, 0x0, 0x0, 0xc, 0x0, 0x0,

    /* U+E6F8 "" */
    0x1f, 0xff, 0xff, 0xff, 0xff, 0x83, 0xff, 0xff,
    0xff, 0xff, 0xfc, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xef, 0x38, 0x0, 0x0, 0x1, 0xce, 0xe3, 0x80,
    0x0, 0x0, 0x1c, 0x7e, 0x38, 0x0, 0x0, 0x1,
    0xc7, 0xe3, 0x80, 0x0, 0x0, 0x1c, 0x7e, 0x38,
    0x0, 0x0, 0x1, 0xc7, 0xe3, 0x80, 0x0, 0x0,
    0x1c, 0x7f, 0xf8, 0x0, 0x0, 0x1, 0xff, 0xff,
    0x80, 0x0, 0x0, 0x1f, 0xff, 0xf8, 0xe, 0x0,
    0x1, 0xff, 0xe3, 0x80, 0xf8, 0x0, 0x1c, 0x7e,
    0x38, 0xf, 0xe0, 0x1, 0xc7, 0xe3, 0x80, 0xff,
    0x0, 0x1c, 0x7e, 0x38, 0xe, 0xfc, 0x1, 0xc7,
    0xe3, 0x80, 0xe3, 0xf0, 0x1c, 0x7f, 0xf8, 0xe,
    0x1f, 0x81, 0xff, 0xff, 0x80, 0xe0, 0x78, 0x1f,
    0xff, 0xf8, 0xe, 0x1f, 0x1, 0xff, 0xe3, 0x80,
    0xe7, 0xc0, 0x1c, 0x7e, 0x38, 0xe, 0xf8, 0x1,
    0xc7, 0xe3, 0x80, 0xfe, 0x0, 0x1c, 0x7e, 0x38,
    0xf, 0x80, 0x1, 0xc7, 0xe3, 0x80, 0xe0, 0x0,
    0x1c, 0x7f, 0xf8, 0x0, 0x0, 0x1, 0xff, 0xff,
    0x80, 0x0, 0x0, 0x1f, 0xff, 0xf8, 0x0, 0x0,
    0x1, 0xff, 0xe3, 0x80, 0x0, 0x0, 0x1c, 0x7e,
    0x38, 0x0, 0x0, 0x1, 0xc7, 0xe3, 0x80, 0x0,
    0x0, 0x1c, 0x7e, 0x38, 0x0, 0x0, 0x1, 0xc7,
    0xe3, 0x80, 0x0, 0x0, 0x1c, 0x7f, 0x38, 0x0,
    0x0, 0x1, 0xce, 0x7f, 0xff, 0xff, 0xff, 0xff,
    0xe3, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff,
    0xff, 0xff, 0xff, 0x80,

    /* U+E795 "" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xfc, 0x0, 0x0, 0x1f, 0xff, 0x80, 0x0, 0xff,
    0xff, 0xf0, 0x1, 0xff, 0xfc, 0xe, 0x0, 0x3f,
    0xe0, 0x1, 0xc0, 0x7, 0x0, 0x0, 0x38, 0x0,
    0xe0, 0x0, 0x7, 0x0, 0x1c, 0x0, 0x0, 0xe0,
    0x3, 0x80, 0x0, 0x1c, 0x0, 0x70, 0x0, 0x3,
    0x80, 0xe, 0x0, 0x0, 0x70, 0x1, 0xc0, 0x0,
    0xe, 0x0, 0x38, 0x0, 0x1, 0xc0, 0x7, 0x0,
    0x0, 0x38, 0x0, 0xe0, 0x0, 0x7, 0x0, 0x1c,
    0x0, 0x0, 0xe0, 0x3, 0x80, 0x0, 0x1c, 0x0,
    0x70, 0x0, 0x3, 0x80, 0xe, 0x0, 0x0, 0x70,
    0x1, 0xc0, 0x0, 0xe, 0x0, 0x38, 0x0, 0x1,
    0xc0, 0x7, 0x0, 0x0, 0x38, 0x0, 0xe0, 0x0,
    0x7, 0x7, 0xfc, 0x0, 0x3f, 0xe3, 0xff, 0x80,
    0x1f, 0xfc, 0xff, 0xf0, 0x7, 0xff, 0xbf, 0xfe,
    0x1, 0xff, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0xff,
    0xf8, 0xf, 0xff, 0xff, 0xff, 0x1, 0xff, 0xff,
    0xff, 0xc0, 0x3f, 0xfe, 0x7f, 0xf0, 0x3, 0xff,
    0x8f, 0xfc, 0x0, 0x7f, 0xe0, 0x7e, 0x0, 0x3,
    0xf0, 0x0,

    /* U+E852 "" */
    0xe0, 0x0, 0x0, 0x0, 0x3, 0x80, 0x0, 0x0,
    0x0, 0xe, 0x3, 0xc0, 0x0, 0x0, 0x38, 0xf,
    0x0, 0x0, 0x0, 0xe0, 0x3c, 0x0, 0x0, 0x3,
    0x80, 0xf0, 0x0, 0x0, 0xe, 0x3, 0xc0, 0x0,
    0x0, 0x39, 0xff, 0xf8, 0xff, 0xfc, 0xe7, 0xff,
    0xe3, 0xff, 0xf3, 0x9f, 0xff, 0x8f, 0xff, 0xce,
    0x3, 0xc0, 0x0, 0x0, 0x38, 0xf, 0x0, 0x0,
    0x0, 0xe0, 0x3c, 0x0, 0x0, 0x3, 0x80, 0xf0,
    0x0, 0x0, 0xe, 0x3, 0xc0, 0x0, 0x0, 0x38,
    0x0, 0x0, 0x0, 0x0, 0xe0, 0x0, 0x0, 0x0,
    0x3, 0x80, 0x0, 0x0, 0x0, 0xe, 0x0, 0x0,
    0x0, 0x0, 0x38, 0x0, 0x0, 0x3, 0x0, 0xe1,
    0x81, 0x80, 0x1e, 0x3, 0x8f, 0xf, 0x0, 0x30,
    0xe, 0x3e, 0x7c, 0x0, 0x0, 0x38, 0x7f, 0xe0,
    0x0, 0x0, 0xe0, 0xff, 0x3, 0xff, 0xf3, 0x80,
    0xf8, 0xf, 0xff, 0xce, 0x7, 0xe0, 0x3f, 0xff,
    0x38, 0x7f, 0xe0, 0x0, 0x0, 0xe3, 0xe7, 0xc0,
    0x0, 0x3, 0x8f, 0xf, 0x0, 0x30, 0xe, 0x18,
    0x18, 0x1, 0xe0, 0x38, 0x0, 0x0, 0x3, 0x0,
    0xe0, 0x0, 0x0, 0x0, 0x3, 0x80, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc,

    /* U+E8C8 "" */
    0x0, 0x0, 0x70, 0x0, 0x0, 0x0, 0x7, 0x0,
    0x0, 0x0, 0x0, 0x70, 0x0, 0x0, 0x0, 0x7,
    0x0, 0x0, 0x0, 0x0, 0x70, 0x0, 0x0, 0x70,
    0x0, 0x0, 0xe0, 0x7, 0x0, 0x0, 0xe, 0x0,
    0x38, 0x0, 0x1, 0xc0, 0x1, 0x81, 0xf8, 0x18,
    0x0, 0x0, 0x7f, 0xe0, 0x0, 0x0, 0xf, 0xff,
    0x0, 0x0, 0x1, 0xf0, 0xf8, 0x0, 0x0, 0x3c,
    0x3, 0xc0, 0x0, 0x7, 0x80, 0x1e, 0x0, 0x0,
    0x70, 0x0, 0xe0, 0x0, 0xf, 0x0, 0xf, 0x0,
    0x0, 0xe0, 0x0, 0x70, 0xf, 0xce, 0x0, 0x7,
    0x3f, 0xfc, 0xe0, 0x0, 0x73, 0xff, 0xce, 0x0,
    0x7, 0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff,

    /* U+E966 "" */
    0x0, 0x0, 0x3f, 0x0, 0x0, 0x0, 0x0, 0xf,
    0xf0, 0x0, 0x0, 0x0, 0x3, 0xff, 0x0, 0x0,
    0x0, 0x0, 0xf9, 0xf0, 0x0, 0x0, 0xf, 0xbe,
    0x1f, 0x7e, 0x0, 0x3, 0xff, 0xc3, 0xff, 0xe0,
    0x0, 0xff, 0xf0, 0x3f, 0xfe, 0x0, 0x3f, 0xf8,
    0x1, 0xff, 0xe0, 0x7, 0x8c, 0x0, 0xc, 0x3c,
    0x0, 0xe0, 0x0, 0x0, 0x7, 0x80, 0x1c, 0x0,
    0x0, 0x0, 0xf0, 0x3, 0xc0, 0x0, 0x0, 0x1e,
    0x0, 0x78, 0x3, 0xf0, 0x7, 0x80, 0xf, 0x1,
    0xff, 0x80, 0x78, 0x1, 0xc0, 0x7f, 0xf8, 0xf,
    0x0, 0xf8, 0x1f, 0xf, 0x81, 0xf8, 0x3f, 0x7,
    0xc0, 0xf8, 0x1f, 0x8f, 0xc0, 0xf0, 0xf, 0x3,
    0xfb, 0xe0, 0x3c, 0x0, 0xf0, 0xf, 0xf8, 0x7,
    0x80, 0x1e, 0x0, 0xff, 0x0, 0xf0, 0x3, 0xc0,
    0x1f, 0xe0, 0x1e, 0x0, 0x78, 0x3, 0xfe, 0x3,
    0xc0, 0xf, 0x0, 0xfb, 0xf0, 0x3c, 0x3, 0xc0,
    0xfe, 0x3f, 0x7, 0xc0, 0xf8, 0x1f, 0x83, 0xe0,
    0x7c, 0x3e, 0x3, 0xe0, 0x1e, 0x7, 0xff, 0x80,
    0xf0, 0x3, 0xc0, 0x7f, 0xe0, 0x1e, 0x0, 0x78,
    0x3, 0xf0, 0x7, 0x80, 0xf, 0x0, 0x0, 0x0,
    0x78, 0x1, 0xe0, 0x0, 0x0, 0xf, 0x0, 0x3c,
    0x0, 0x0, 0x1, 0xe0, 0x7, 0x84, 0x0, 0xc,
    0x3c, 0x0, 0xff, 0xe0, 0x7, 0xff, 0x80, 0xf,
    0xff, 0x3, 0xff, 0xe0, 0x0, 0xff, 0xf0, 0xff,
    0xf8, 0x0, 0xf, 0xbe, 0x1f, 0x7e, 0x0, 0x0,
    0x3, 0xe7, 0xc0, 0x0, 0x0, 0x0, 0x3f, 0xf0,
    0x0, 0x0, 0x0, 0x3, 0xfc, 0x0, 0x0, 0x0,
    0x0, 0x3f, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 704, .box_w = 41, .box_h = 37, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 190, .adv_w = 704, .box_w = 39, .box_h = 27, .ofs_x = 3, .ofs_y = 3},
    {.bitmap_index = 322, .adv_w = 704, .box_w = 34, .box_h = 39, .ofs_x = 5, .ofs_y = -3},
    {.bitmap_index = 488, .adv_w = 704, .box_w = 44, .box_h = 37, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 692, .adv_w = 704, .box_w = 35, .box_h = 35, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 846, .adv_w = 704, .box_w = 38, .box_h = 37, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 1022, .adv_w = 704, .box_w = 36, .box_h = 36, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1184, .adv_w = 704, .box_w = 43, .box_h = 41, .ofs_x = 1, .ofs_y = -4}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x2d, 0x83, 0xb8, 0x155, 0x212, 0x288, 0x326
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 58944, .range_length = 807, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 8, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t font_icon44 = {
#else
lv_font_t font_icon44 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 41,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if FONT_ICON44*/

