#include "console.h"
#include "draw.h"
#include <chrono>
#include <thread>

// 在乘客信息栏打印乘客信息
void printPassengerLog(const char *s) {
    int x = xPassengerConsoleStart;
    int y = yPassengerConsoleStart;
    DrawString(s, x, y);
}
// 全局变量：记录当前打印位置
int currentY = 0;

// 模拟日志输出的函数
void printLogWithMargin(int x, int y, const std::vector<std::string>& logs) {
    // 获取窗口大小，防止越界
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int maxWidth = csbi.dwSize.X;  // 最大宽度
    int maxHeight = csbi.dwSize.Y; // 最大高度

    // 确保起始位置合法
    if (x < 0 || y < 0 || x >= maxWidth || y >= maxHeight) {
        std::cerr << "Error: Invalid margins (x or y out of bounds).\n";
        return;
    }

    // 如果 currentY 小于 y，初始化到指定顶部间距
    if (currentY < y) {
        currentY = y;
    }

    // 遍历日志内容逐行输出
    for (const auto& log : logs) {
        if (currentY >= maxHeight) {
            std::cerr << "\nError: Exceeded console height limit. Clearing screen...\n";
            system("cls"); // 清屏
            currentY = y;  // 重置打印位置
        }

        // 设置光标位置，并输出日志
        setCursorPosition(x, currentY);
        std::cout << log.substr(0, maxWidth - x); // 防止超出屏幕宽度

        // 模拟延迟（类似 apt install 的逐行更新效果）
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        currentY++; // 移动到下一行
    }
}
