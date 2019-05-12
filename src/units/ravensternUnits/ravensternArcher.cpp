//
// Created by Dima Zapolsky on 09/05/2019.
//

#include "ravensternArcher.h"
#include <sstream>

RavensternArcher::RavensternArcher() {
    accuracy = {30, 37, 45, 52, 60, 66, 72, 76, 80, 85};
    damage = {60, 68, 74, 80, 85};
    attackSpeed = {30, 45, 60, 72, 85};
    maxDistance = {50, 57, 65, 72, 78, 82, 87, 92, 97, 100};
    dead = false;
    skillLevel = 0;
    equipmentLevel = 0;
    canCarry = {2, 4, 6, 7, 8};
    food = {1, 1, 1, 2, 2};
    cost = {10, 18, 24, 32, 50};
    for (auto & x : accuracy) {
        x = int(double(x) * (1800 + rand() % 401) / 2000.);
    }
    for (auto & x : damage) {
        x = int(double(x) * (1800 + rand() % 401) / 2000.);
    }
    for (auto & x : attackSpeed) {
        x = int(double(x) * (1800 + rand() % 401) / 2000.);
    }
    for (auto & x : maxDistance) {
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

std::string RavensternArcher::getName() const {
    std::ostringstream str;
    str << "Равенстернский лучник (" << skillLevel << ", " << equipmentLevel << ")";
    return str.str();
}