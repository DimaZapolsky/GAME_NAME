//
// Created by Dima Zapolsky on 09/05/2019.
//

#include "sarleonHorseman.h"
#include <sstream>

SarleonHorseman::SarleonHorseman() {
    horseSpeed = {75, 80, 85, 90, 95};
    horseArmor = {35, 41, 46, 51, 57};
    armor = {50, 55, 60, 65, 69};
    mobility = {50, 59, 67, 74, 80};
    damage = {58, 63, 67, 72, 77, 82, 88, 93, 100};
    dead = false;
    skillLevel = 0;
    equipmentLevel = 0;
    canCarry = {9, 11, 14, 15, 16};
    food = {3, 3, 4, 5, 5};
    cost = {18, 26, 34, 40, 47};
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

std::string SarleonHorseman::getName() const {
    std::ostringstream str;
    str << "Сарлеонский кавалерист (" << skillLevel << ", " << equipmentLevel << ")";
    return str.str();
}