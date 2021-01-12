# MM32 Startup Libraries / MM32 启动库

MM32 C language startup library, supports IAR, KEIL (ARMCC, ARMCLANG) and GCC.

MM32 C 语言启动库，支持 IAR、KEIL（ARMCC、ARMCLANG）和 GCC。

This repository contains / 本仓库包含：
 - startup files / 启动文件
 - header files / 头文件
 - clock initialization files / 时钟初始化文件

## How to use / 使用方式

### Recommend / 推荐

Add to the project via Git submodule. 

通过 Git 子模块方式添加到项目中。

```bash
git submodule add http://122.112.241.212:7700/liuyq/mm32_startup.git
```

If you want to add to the specified path, please append the path at the end of the above command. 

如果想要添加到指定路径，请在上面的命令最后追加路径。

### Not recommended / 不推荐

下载源代码，复制到您的项目中。

### GNU Arm Embedded Toolchain

Add GNU Arm Embedded Toolchain Path to Environment variable. e.g.:

`C:\Program Files (x86)\GNU Arm Embedded Toolchain\10 2020-q4-major\bin\`

For VS Code `.vscode/settings.json`:

```json
{
    "C_Cpp.default.compilerPath": "arm-none-eabi-gcc.exe",
    "C_Cpp.default.compilerPath": [
        "${workspaceFolder}\\inc\\",
        "C:\\Users\\Kismet\\AppData\\Local\\Arm\\Packs\\ARM\\CMSIS\\5.7.0\\CMSIS\\Core\\Include\\"
    ],
    "C_Cpp.default.defines": [
        "__MM0Q1",
        "CLOCK=8000000"
    ]
}
