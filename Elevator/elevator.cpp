#include "elevator.h"
#include "people.h"
#include <algorithm>
#include "console.h"



Elevator::Elevator() {
    this->elevatorDirection = 'd';
    this->elevatorPositionX = 1;
    this->elevatorPositionY = 1;
    drawElevator(); 
}




// ��һ�����ݡ���������
void Elevator::drawElevatorWithCoordinates(int x, int y) {
    for (int i = 0; i < ELEVATOR_WIDTH; i++) {
        drawBlock(x + i, y);
        drawBlock(x + i, y + ELEVATOR_HEIGHT - 1);
    }

    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        drawBlock(x, y + i);
        drawBlock(x + ELEVATOR_WIDTH - 1, y + i);
    }
}

// ɾ��ָ������ĵ���
void Elevator::deleteElevatorWithCoordinates(int x, int y) {
    for (int i = 0; i < ELEVATOR_WIDTH; i++) {
        deleteGrid(x + i, y);
        deleteGrid(x + i, y + ELEVATOR_HEIGHT - 1);
    }

    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        deleteGrid(x, y + i);
        deleteGrid(x + ELEVATOR_WIDTH - 1, y + i);
    }
    //  drawElevatorDirection();
}

// ��һ�����ݣ�λ���ɳ���ٿ�
void Elevator::drawElevator() {
    for (int i = 0; i < ELEVATOR_WIDTH; i++) {
        drawBlock(elevatorPositionX + i, elevatorPositionY);
        drawBlock(elevatorPositionX + i,
                  elevatorPositionY + ELEVATOR_HEIGHT - 1);
    }

    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        drawBlock(elevatorPositionX, elevatorPositionY + i);
        drawBlock(elevatorPositionX + ELEVATOR_WIDTH - 1,
                  elevatorPositionY + i);
    }

    //  drawElevatorDirection();

}

// ɾ�������أ�����
void Elevator::deleteElevator() {
    for (int i = 0; i < ELEVATOR_WIDTH; i++) {
        deleteGrid(elevatorPositionX + i, elevatorPositionY);
        deleteGrid(elevatorPositionX + i,
                   elevatorPositionY + ELEVATOR_HEIGHT - 1);
    }

    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        deleteGrid(elevatorPositionX, elevatorPositionY + i);
        deleteGrid(elevatorPositionX + ELEVATOR_WIDTH - 1,
                   elevatorPositionY + i);
    }
}

// ��������һ�񣬣�����ɾ��ԭ�еĵ��ݣ�Ȼ�����»��Ƶ��ݣ�
void Elevator::goDownElevator() {
    // ���·���
    elevatorDirection = 'd';
    // ɾ������
    deleteElevator();
    // ������������
    elevatorPositionY += 1;
    // ���»��Ƶ���
    drawElevator();
}

// ��������һ�񣬣�����ɾ��ԭ�еĵ��ݣ�Ȼ�����»��Ƶ��ݣ�
void Elevator::goUpElevator() {
    elevatorDirection = 'u';
    deleteElevator();
    elevatorPositionY -= 1;
    drawElevator();
}

// ����5��
void Elevator::goDownFloor() {
    std::vector<std::string> log;
    log.push_back("��������");
    printLogWithMargin(61, 1, log);
    this->currentFloor -= 1;
    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        goDownElevator();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

// ����5��
void Elevator::goUpFloor() {
    std::vector<std::string> log;
    log.push_back("��������");
    printLogWithMargin(61, 1, log);
    this->currentFloor += 1;
    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        goUpElevator();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}


void Elevator::closeDoor() {
    int doorX = ELEVATOR_WIDTH;
    int doorY = elevatorPositionY;

    for (int i = 0; i < ELEVATOR_HEIGHT; i++) {
        deleteGrid(doorX, doorY + i);
    }
}

void Elevator::drawElevatorDirection() {
    int x = elevatorPositionX + ELEVATOR_WIDTH - 2;
    int y = elevatorPositionY + ELEVATOR_HEIGHT / 2;

    if (elevatorDirection == 'u') {
        DrawUpTriangle(x, y);
    } else {
        DrawDownTriangle(x, y);
    }
}

void Elevator::go(char direction) {
    if (direction == 'd') {
        goDownFloor();
    } else if (direction == 'u') {
        goUpFloor();
    }
}


// change direction.
void Elevator::changeDirection() {
    if (elevatorDirection == 'u') {
        elevatorDirection = 'd';
    } else {
        elevatorDirection = 'u';
    }
}

void Elevator::pushPeople(People people) {
    this->peopleList.push_back(people);

}


bool Elevator::isVoid() {
    if (peopleList.empty()) {
        return true;
    } 
    return false;
}


std::vector<People> Elevator::clean(int floorNum) {
    std::vector<People> gone = {};

    for (auto people : peopleList) {
        if (people.gotoFloor == floorNum)
        people.peopleLeaveLog(floorNum);
    }
    
    auto it = std::remove_if(peopleList.begin(), peopleList.end(), [&gone, floorNum] (const People& people) {
            if (people.gotoFloor == floorNum) {
            gone.push_back(people);
            return true;
            }
            return false;
            }
            );

    peopleList.erase(it, peopleList.end());
        return gone;
};
