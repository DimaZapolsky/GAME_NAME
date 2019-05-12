//
// Created by Dima Zapolsky on 09/05/2019.
//

#include "ravensternInfantryman.h"
#include <sstream>

RavensternInfantryman::RavensternInfantryman() {
    haveShield = {false, false, false, true, true};
    damage = {30, 37, 44, 52, 60, 62, 69, 76, 82, 88};
    armor = {64, 68, 72, 76, 80};
    speed = {57, 63, 68, 75, 80};
    dead = false;
    skillLevel = 0;
    equipmentLevel = 0;
    canCarry = {4, 4, 5, 5, 6};
    food = {1, 1, 2, 3, 3};
    cost = {16, 20, 26, 32, 35};
    for (auto & x : armor) {
        x = int(double(x) * (1800 + rand() % 401) / 2000.);
    }
    for (auto & x : speed) {
        x = int(double(x) * (1800 + rand() % 401) / 2000.);
    }
    for (auto & x : damage) {
        x = int(double(x) * (1800 + rand() % 401) / 2000.);
    }
    for (auto & x : canCarry) {
        x = int(double(x) * (1800 + rand() % 401) / 2000.);
    }
    for (auto & x : food) {
        x = int(double(x) * (1800 + rand() % 401) / 2000.);
    }
    for (auto & x : cost) {
        x = int(double(x) * (1800 + rand() % 401) / 2000.);
    }
}

std::string RavensternInfantryman::getName() const {
    std::ostringstream str;
    str << "Равенстернский пехотинец (" << skillLevel << ", " << equipmentLevel << ")";
    return str.str();
}