//
// Created by Dima Zapolsky on 09/05/2019.
//

#include "ravensternHorseman.h"
#include <sstream>

RavensternHorseman::RavensternHorseman() {
    horseSpeed = {65, 70, 75, 80, 85};
    horseArmor = {30, 37, 54, 61, 67};
    armor = {60, 64, 68, 73, 77};
    mobility = {65, 73, 80, 87, 93};
    damage = {50, 56, 62, 68, 75, 81, 87, 93, 100};
    dead = false;
    skillLevel = 0;
    equipmentLevel = 0;
    canCarry = {8, 10, 12, 13, 15};
    food = {3, 3, 4, 4, 5};
    cost = {22, 31, 39, 49, 60};
    for (auto & x : horseArmor) {
        x = int(double(x) * (1800 + rand() % 401) / 2000.);
    }
    for (auto & x : horseSpeed) {
        x = int(double(x) * (1800 + rand() % 401) / 2000.);
    }
    for (auto & x : armor) {
        x = int(double(x) * (1800 + rand() % 401) / 2000.);
    }
    for (auto & x : mobility) {
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

std::string RavensternHorseman::getName() const {
    std::ostringstream str;
    str << "Равенстернский кавалерист (" << skillLevel << ", " << equipmentLevel << ")";
    return str.str();
}