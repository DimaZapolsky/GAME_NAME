//
// Created by Dima Zapolsky on 09/05/2019.
//

#include "sarleonArcher.h"
#include <sstream>

SarleonArcher::SarleonArcher() {
    accuracy = {25, 32, 39, 46, 52, 57, 61, 66, 70, 75};
    damage = {70, 72, 75, 78, 80};
    attackSpeed = {25, 38, 52, 60, 65};
    maxDistance = {54, 58, 61, 65, 69, 74, 78, 82, 86, 90};
    dead = false;
    skillLevel = 0;
    equipmentLevel = 0;
    canCarry = {3, 5, 6, 8, 8};
    food = {1, 1, 2, 2, 2};
    cost = {15, 21, 29, 36, 42};
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

std::string SarleonArcher::getName() const {
    std::ostringstream str;
    str << "Сарлеонский лучник (" << skillLevel << ", " << equipmentLevel << ")";
    return str.str();
}