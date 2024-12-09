#include "people.h"
#include "console.h"
#include <array>
#include <cmath>
#include <random>

int People::peopleID = 1;

// 人的初始化函数
People::People(int initFloor, bool valid) {
    this->id = peopleID;
    peopleID++;

    this->weight = generateWeight();
    this->gotoFloor = generateFloor();
    this->initFloor = initFloor;
    this->valid = valid;


    peopleLog();
}

// 随机生成体重（正态分布）
double People::generateWeight() {
    std::random_device rd;
    std::mt19937 gen(rd());

    double mean = 70.0;   // 均值
    double stddev = 10.0; // 标准差

    std::normal_distribution<> d(mean, stddev);

    double weight = std::round(d(gen));

    return weight;
}
// 随机生成想去的楼层
int People::generateFloor() {
    // 创建一个随机数生成器
    std::random_device rd;
    std::mt19937 gen(rd());

    // 定义楼层数组
    std::array<int, 5> floors = {1, 2, 3, 4, 5};

    // 创建一个均匀分布
    std::uniform_int_distribution<> dist(0, floors.size() - 1);

    // 生成一个随机索引
    int index = dist(gen);

    // 返回对应的楼层
    return floors[index];
}

void People::peopleLog() {
    char buffer[100];
    sprintf_s(buffer, "[info] 已生成 id%d 体重%.0lf 初始楼层 %d 目标楼层 %d 的人", this->id, this->weight, this->initFloor,
              this->gotoFloor);

    // 将 char 数组转换为 std::string
    std::string logEntry(buffer);

    // 创建一个包含单个字符串的向量
    std::vector<std::string> logs = {logEntry};

    // 调用 printLogWithMargin 函数
    printLogWithMargin(61, 1, logs);
}

void People::peopleLeaveLog(int floorNum) {
    char buffer[100];
    sprintf_s(buffer, "[info] %d 号乘客已从 %d层 离开", this->id, floorNum);

    // 将 char 数组转换为 std::string
    std::string logEntry(buffer);

    // 创建一个包含单个字符串的向量
    std::vector<std::string> logs = {logEntry};

    // 调用 printLogWithMargin 函数
    printLogWithMargin(61, 1, logs);
}



















