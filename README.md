# ACPM

A modern C++23 project built with MinGW.

## Build with MinGW
```bash
cmake -B build -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build build

## Run

bash
.\build\bin\ACPM.exe

## Requirements

- CMake 3.20+
- MinGW-w64 with GCC 13+ (C++23 support)
- Make sure MinGW bin directory is in your PATH

## Install MinGW

Download from: https://www.mingw-w64.org/
Or use MSYS2: https://www.msys2.org/

bash
# With MSYS2
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake
