#include "floorManager.h"
#include "people.h"


FloorManager::FloorManager() {
    for (int i = 1; i <= 5; i++) {
        Floor floor = Floor(i);
        FloorList.push_back(floor);
    };
};

// used to generateRandomPeople in runtime
void FloorManager::generateRandomPeople() { int num = uniform_int(5);
    People people = People(num);
    FloorList[num - 1].peopleList.push_back(people);
    FloorList[num - 1].peopleNum++;
}

// x is current floor num
bool FloorManager::checkUp(int x) {
    if (x == 5) {
        return false;
    }
    for (int i = x-1; i < 5; i++) {
        Floor now = this->FloorList[i];
        if (now.peopleNum > 0) {
            return true;
        }
    }

    return false;
}
bool FloorManager::checkDown(int x) {
    if ( x == 1 ) {
        return false;
    }

    for (int i = x - 1; i >= 0; i--) {
        Floor now = this->FloorList[i];
        if (now.peopleNum > 0) {
            return true;
        }
    }

    return false;
}

People FloorManager::popPeople(int floorNum) {
    // it must not empty because FloorManager init to have them
    People people = this->FloorList[floorNum - 1].pop();
    return people;
}

bool FloorManager::isVoid() {
    bool isnull = false;
    for(auto floor : FloorList) {
        if (!floor.check()) {
            isnull = true;
        }
    }
    return isnull;
}









