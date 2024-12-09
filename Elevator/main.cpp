#include "elevator.h"
#include "window.h"
#include <cmath>
#include <windows.h>
#include <wingdi.h>
#include "floorManager.h"
#include "global.h"
#include "console.h"

// we need a class for elevator, a class for floor, and a class for all floors (floorManager).

// we are going to make a structure
int main() {
    getchar();
    
    system("cls");
    // elevator 14 * 7
    // floor 14 * 8
    // console ??
   windowInit();    // draw the window, only draws the border
    
    FloorManager FM = FloorManager();   
    // draw the floors, need to draw the floor, people on floor, floor number, init direction
    Elevator E = Elevator(); // init and draw the elevator

    // a recurser that continue, generate people based on round;
    for (int round=0; round < 300; round ++) {
        windowInit(); 
        if (FM.isVoid() && E.isVoid()) {
            std::vector<std::string> v;
            v.push_back("[info] All the passengers are gone!!!");
            printLogWithMargin(61, 1, v);
            return 0;
        }
        if (round % RT == 0) {
            FM.generateRandomPeople();
        }
        // fetch current elevator floor and direction
        int currentFloor = E.currentFloor;
        char currentDirection = E.elevatorDirection;

        // is people on that direction?
        bool peopleThere = false;
        if (currentDirection == 'u') {
            peopleThere = FM.checkUp(currentFloor); // it also need to check if we go out bound

        } else if (currentDirection == 'd') {
            peopleThere = FM.checkDown(currentFloor);
        }

        // if people there, pick them
        // else change direction
        if (peopleThere) { 
            E.go(currentDirection); // auto change its direciton property.
            People pickedPeople = FM.popPeople(E.currentFloor);
            E.clean(currentFloor);
            if (pickedPeople.valid == false) {
                continue;
            }
            E.pushPeople(pickedPeople);

        } else {
            E.changeDirection();
            continue;
        }
    }
}
