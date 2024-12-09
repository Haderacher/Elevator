#include "draw.h"
#include <Windows.h>
#include <stdio.h>

// ԭ���������λ��
void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// �ñ�׼���֣��趨���λ��
void setCursorPositionWithGrid(int x, int y) {
    COORD coord;
    coord.X = x * 2;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// ���ƴ�ֱ
void drawVerticalLine(int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("|");
}
// ����һ��ˮƽ��(x, y)
void drawHorizontalLine(int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("==");
}

// ����һ������x, y��
void drawBlock(int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("*");
}

// ��һ��ǽ
void drawWallBlock(int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("#");
}

// ɾ��һ�����飨�����ַ���
void deleteGrid(int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("  ");
};

// ��ָ��λ��һ������
void drawNumber(int num, int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("%d", num);
}

// ��ָ��λ�ô�ӡһ���ַ�
void DrawChar(char c, int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("%c", c);
}

// ��ָ��λ������ַ���
void DrawString(const char s[], int x, int y) {
    setCursorPositionWithGrid(x, y);
    printf("%s", s);
}

// ==========������������������ʵ�ĵ����ǣ���  ��  �� ��

// ��һ��������
void DrawUpTriangle(int x, int y) {
    setCursorPositionWithGrid(x, y);
    DrawString("��", x, y);
}

// ��һ��������
void DrawDownTriangle(int x, int y) {
    // setCursorPositionWithGrid(x, y);
    DrawString("��", x, y);
}

// debug��;
void DrawDebug(int x, int y) {
    // setCursorPositionWithGrid(x, y);
    DrawString("&&", x, y);
}