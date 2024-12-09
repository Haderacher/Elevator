#include "draw.h"
#include <Windows.h>
#include <stdio.h>

// 原生设置鼠标位置
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 用标准布局，设定鼠标位置
void setCursorPositionWithGrid(int x, int y) {
    COORD coord;
    coord.X = x * 2;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// 绘制垂直
void drawVerticalLine(int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("|");
}
// 绘制一个水平线(x, y)
void drawHorizontalLine(int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("==");
}

// 绘制一个方格（x, y）
void drawBlock(int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("*");
}

// 画一个墙
void drawWallBlock(int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("#");
}

// 删除一个方块（两个字符）
void deleteGrid(int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("  ");
};

// 在指定位置一个数字
void drawNumber(int num, int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("%d", num);
}

// 在指定位置打印一个字符
void DrawChar(char c, int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("%c", c);
}

// 在指定位置输出字符串
void DrawString(const char s[], int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("%s", s);
}

// ==========以下用于设置三角形实心倒三角：▲  △  ▼ ▽

// 画一个正三角
void DrawUpTriangle(int x, int y) {
    setCursorPositionWithGrid(x, y);
    DrawString("▲", x, y);
}

// 画一个倒三角
void DrawDownTriangle(int x, int y) {
    // setCursorPositionWithGrid(x, y);
    DrawString("▼", x, y);
}

// debug用途
void DrawDebug(int x, int y) {
    // setCursorPositionWithGrid(x, y);
    DrawString("&&", x, y);
}