# MM32 Startup Libraries / MM32 启动库

MM32 C language startup library, supports IAR, KEIL (ARMCC, ARMCLANG) and GCC.

MM32 C 语言启动库，支持 IAR、KEIL（ARMCC、ARMCLANG）和 GCC。

This repository contains / 本仓库包含：

- startup files / 启动文件
- header files / 头文件
- clock initialization files / 时钟初始化文件

## Chip Core Version Define

| Core Version | Chip                           |
| :----------: | :----------------------------- |
|  \_\_MM0N1   | MM32L0xx, MM32F031             |
|  \_\_MM3N1   | MM32F103                       |
|  \_\_MM3O1   | MM32F103                       |
|  \_\_MM0P1   | MM32SPIN2x                     |
|  \_\_MM0Q1   | MM32F003, MM32F031, MM32SPIN0x |
|  \_\_MM0S1   | MM32F032, MM32F013x            |
|  \_\_MM0T1   | MM32F0010                      |
|  \_\_MM0U1   | MM32F327x                      |

## How to use / 使用方式

### Recommend / 推荐

Add to the project via Git submodule.

通过 Git 子模块方式添加到项目中。

```bash
git submodule add https://github.com/PYGC/mm32_startup.git
```

If you want to add to the specified path, please append the path at the end of the above command.

如果想要添加到指定路径，请在上面的命令最后追加路径，例如：

```bash
git submodule add https://github.com/PYGC/mm32_startup.git lib/startup
```

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
        "${workspaceFolder}/inc/",
        "${GITWORK_PATH}/github.com/ARM-software/CMSIS_5/CMSIS/Core/Include/**"
    ],
    "C_Cpp.default.defines": ["__MM0Q1", "CLOCK=8000000"]
}
```
