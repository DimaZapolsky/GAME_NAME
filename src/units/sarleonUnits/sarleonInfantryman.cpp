//
// Created by Dima Zapolsky on 09/05/2019.
//

#include "sarleonInfantryman.h"
#include <sstream>

SarleonInfantryman::SarleonInfantryman() {
    haveShield = {false, false, true, true, true};
    damage = {40, 44, 49, 54, 58, 62, 67, 71, 75, 80};
    armor = {64, 68, 72, 76, 80};
    speed = {60, 66, 72, 78, 85};
    dead = false;
    skillLevel = 0;
    equipmentLevel = 0;
    canCarry = {4, 5, 5, 6, 7};
    food = {1, 2, 2, 2, 3};
    cost = {14, 19, 24, 29, 33};
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

std::string SarleonInfantryman::getName() const {
    std::ostringstream str;
    str << "Сарлеонский пехотинец (" << skillLevel << ", " << equipmentLevel << ")";
    return str.str();
}