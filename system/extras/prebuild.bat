@echo off
set BUILD_PATH=%1
set BUILD_SOURCE_PATH=%2
set BOARD_PLATFORM_PATH=%3

:: 如果 sketch 目录不存在，则创建该目录
if not exist "%BUILD_PATH%\sketch" mkdir "%BUILD_PATH%\sketch"

:: 如果原始的 sketch 目录中不存在 build_opt.h 文件，则创建空的 build.opt 文件
:: 然后添加或追加 -fmacro-prefix-map 选项以将 __FILE__ 的绝对路径转换为相对路径
:: （即包含 boards.txt 文件的文件夹）。
if not exist "%BUILD_SOURCE_PATH%\build_opt.h" (
  echo -e "-fmacro-prefix-map=\"%BOARD_PLATFORM_PATH:\=\\%\"=." > "%BUILD_PATH%\sketch\build.opt"
) else (
  :: 否则将 build_opt.h 文件复制为 build.opt
  :: 这是对 arduino-cli 执行的头文件预处理的一种解决方法
  :: 参见 https://github.com/arduino/arduino-cli/issues/1338
  copy "%BUILD_SOURCE_PATH%\build_opt.h" "%BUILD_PATH%\sketch\build.opt"
  echo -e "-fmacro-prefix-map=\"%BOARD_PLATFORM_PATH:\=\\%\"=." >> "%BUILD_PATH%\sketch\build.opt"
)

:: 强制包含 SrcWrapper 库
echo #include ^<SrcWrapper.h^> > "%BUILD_PATH%\sketch\SrcWrapper.cpp"
