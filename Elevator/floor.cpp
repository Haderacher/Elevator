#include "floor.h"

Floor::Floor(int floorNum) {
    int peopleNum = uniform_int(this->peopleMax);

    this->peopleNum = peopleNum;

    for (int i = 0;i < peopleNum; i++) {
        People people = People(floorNum);
        this->peopleList.push_back(people);
    }
}

People Floor::pop() {
    // check if empty, but we don't want to go wrong!
    //if (this->peopleList.empty()) {
      //  std::cerr << "peopleList empty";
     //   system("exit");
    //}

    if (this->peopleList.empty()) {
        People people = People(123, false);
        return people;
    }
    People people = peopleList[0];
    
    // erase the first
    peopleList.erase(peopleList.begin());
    this->peopleNum--;
    return people;
}


bool Floor::check() {
    if (this->peopleList.empty()) {
        return false;
    } else {
        return true;
    }
}    
