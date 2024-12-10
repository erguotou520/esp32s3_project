`font_icon.c` 包含文字`0xe8c8,0xe795,0xe640,0xe6f8,0xe66d,0xe6c3,0xe966,0xe852`
对应的utf8编码分别是`\xee\xa3\x88,\xee\x9e\x95,\xee\x99\x80,\xee\x9b\xb8,\xee\x99\xad,\xee\x9b\x83,\xee\xa5\xa6,\xee\xa1\x92`
执行`node assets/convert.mjs` 可以得到对应的utf8编码

常见中文字符范围
```sh
# https://www.zhangxinxu.com/study/201611/chinese-language-unicode-range.html
# 极限压缩
0x30-0x39, 0x61-0x7a, 0x41-0x5a, 0x4e00-0x9fa5
```
