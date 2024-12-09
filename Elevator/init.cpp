#include "init.h"
#include <Windows.h>
#include <consoleapi.h>

void setConsoleUTF8() {
    SetConsoleOutputCP(CP_UTF8); // �����������Ϊ UTF-8
    SetConsoleCP(CP_UTF8);       // �����������Ϊ UTF-8
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

    // ��ȡ����̨֧�ֵ���󴰿ڴ�С
    COORD maxSize = GetLargestConsoleWindowSize(hOut);
    if (columns > maxSize.X || rows > maxSize.Y) {
        std::cerr
            << "Error: Requested size exceeds maximum console window size."
            << std::endl;
        return;
    }

    // Step 1: ��������С����
    COORD bufferSize;
    bufferSize.X = columns;
    bufferSize.Y = rows;

    if (!SetConsoleScreenBufferSize(hOut, bufferSize)) {
        std::cerr << "Error: Unable to set console screen buffer size"
                  << std::endl;
        return;
    }

    // Step 2: ���ô��ڴ�С
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