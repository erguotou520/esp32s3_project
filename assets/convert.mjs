// 读取json并将unicode拼接0x并以英文逗号间隔输出
// 同时将unicode值转换成utf-8的值进行输出

import fs from 'fs';

const jsonPath = new URL('iconfont.json', import.meta.url).pathname;
const jsonData = fs.readFileSync(jsonPath, 'utf8');
const data = JSON.parse(jsonData);

const unicodeValues = data.glyphs.map(item => `0x${item.unicode}`);
const utf8Values = data.glyphs.map(item => {
  // 将16进制字符串转换为数字
  const codePoint = parseInt(item.unicode, 16);
    
  // 创建一个只包含这个码点的Buffer
  const buf = Buffer.from(String.fromCodePoint(codePoint));
  
  // 将Buffer转换为十六进制字符串表示
  let hexString = buf.toString('hex');
  
  // 将十六进制字符串转换为\xXX格式
  let result = '';
  for (let i = 0; i < hexString.length; i += 2) {
      result += '\\x' + hexString.slice(i, i + 2);
  }
  
  return result;
});

console.log(unicodeValues.join(', '));
console.log(utf8Values.join(' '));