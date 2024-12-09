#include "init.h"
#include <Windows.h>
#include <consoleapi.h>

void setConsoleUTF8() {
    SetConsoleOutputCP(CP_UTF8); // 设置输出编码为 UTF-8
    SetConsoleCP(CP_UTF8);       // 设置输入编码为 UTF-8
}

void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
        return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
        return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

void setConsoleSize(int columns, int rows) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) {
        std::cerr << "Error: Unable to get console handle" << std::endl;
        return;
    }

    // 获取控制台支持的最大窗口大小
    COORD maxSize = GetLargestConsoleWindowSize(hOut);
    if (columns > maxSize.X || rows > maxSize.Y) {
        std::cerr
            << "Error: Requested size exceeds maximum console window size."
            << std::endl;
        return;
    }

    // Step 1: 缓冲区大小设置
    COORD bufferSize;
    bufferSize.X = columns;
    bufferSize.Y = rows;

    if (!SetConsoleScreenBufferSize(hOut, bufferSize)) {
        std::cerr << "Error: Unable to set console screen buffer size"
                  << std::endl;
        return;
    }

    // Step 2: 设置窗口大小
    SMALL_RECT windowSize;
    windowSize.Left = 0;
    windowSize.Top = 0;
    windowSize.Right = columns - 1;
    windowSize.Bottom = rows - 1;

    if (!SetConsoleWindowInfo(hOut, TRUE, &windowSize)) {
        std::cerr << "Error: Unable to set console window size" << std::endl;
        return;
    }
}

void Init() {
    enableANSI();
    setConsoleSize(HEIGHT * 2, WIDTH);
}