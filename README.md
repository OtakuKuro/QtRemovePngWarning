# QtRemovePngWarning
Qt导入Png后会报出警告
```
libpng warning: iCCP: known incorrect sRGB profile
```
用Qt自己程序读取并保存后即可消除该警告.
改程序为递归读取指定文件夹中所有Png图片并重新保存，以消除该警告
