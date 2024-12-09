#include "people.h"
#include "console.h"
#include <array>
#include <cmath>
#include <random>

int People::peopleID = 1;

// �˵ĳ�ʼ������
People::People(int initFloor, bool valid) {
    this->id = peopleID;
    peopleID++;

    this->weight = generateWeight();
    this->gotoFloor = generateFloor();
    this->initFloor = initFloor;
    this->valid = valid;


    peopleLog();
}

// ����������أ���̬�ֲ���
double People::generateWeight() {
    std::random_device rd;
    std::mt19937 gen(rd());

    double mean = 70.0;   // ��ֵ
    double stddev = 10.0; // ��׼��

    std::normal_distribution<> d(mean, stddev);

    double weight = std::round(d(gen));

    return weight;
}
// ���������ȥ��¥��
int People::generateFloor() {
    // ����һ�������������
    std::random_device rd;
    std::mt19937 gen(rd());

    // ����¥������
    std::array<int, 5> floors = {1, 2, 3, 4, 5};

    // ����һ�����ȷֲ�
    std::uniform_int_distribution<> dist(0, floors.size() - 1);

    // ����һ���������
    int index = dist(gen);

    // ���ض�Ӧ��¥��
    return floors[index];
}

void People::peopleLog() {
    char buffer[100];
    sprintf_s(buffer, "[info] ������ id%d ����%.0lf ��ʼ¥�� %d Ŀ��¥�� %d ����", this->id, this->weight, this->initFloor,
              this->gotoFloor);

    // �� char ����ת��Ϊ std::string
    std::string logEntry(buffer);

    // ����һ�����������ַ���������
    std::vector<std::string> logs = {logEntry};

    // ���� printLogWithMargin ����
    printLogWithMargin(61, 1, logs);
}

void People::peopleLeaveLog(int floorNum) {
    char buffer[100];
    sprintf_s(buffer, "[info] %d �ų˿��Ѵ� %d�� �뿪", this->id, floorNum);

    // �� char ����ת��Ϊ std::string
    std::string logEntry(buffer);

    // ����һ�����������ַ���������
    std::vector<std::string> logs = {logEntry};

    // ���� printLogWithMargin ����
    printLogWithMargin(61, 1, logs);
}



















