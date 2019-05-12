//
// Created by Dima Zapolsky on 09/05/2019.
//

#include "warrior.h"
#include "battle.h"
#include "probability_functions.h"
#include <cmath>
#include <iostream>

double Warrior::getChance(Battle battle, std::shared_ptr<Warrior> enemy) const {
    return normed_probability_function(this->calculate_strength(battle.getTerrain()),
            enemy->calculate_strength(battle.getTerrain()), 1e10);
}

bool Warrior::getDead() const {
    return dead;
}

void Warrior::setDead(bool value) {
    dead = value;
}

void Warrior::upSkillLevel(bool show) {
    if (show)
        std::cout << getName() << " --> ";
    skillLevel++;
    if (show)
        std::cout << getName() << std::endl;
}

void Warrior::upEquipmentLevel(bool show) {
    if (show)
        std::cout << getName() << " --> ";
    equipmentLevel++;
    if (show)
        std::cout << getName() << std::endl;
}

int Warrior::getCanCarry() const {
    return canCarry[std::min((int)canCarry.size() - 1, skillLevel)];
}

int Warrior::getCost() const {
    return cost[std::min((int)cost.size() - 1, skillLevel)];
}

int Warrior::getFood() const {
    return food[std::min((int)food.size() - 1, skillLevel)];
}

std::vector <std::shared_ptr<Warrior> > Warrior::getAllWarriors() {
    std::vector <std::shared_ptr<Warrior> > ans;
    ans.push_back(shared_from_this());
    return ans;
}

std::string Warrior::getInfo() {
    return std::string(depth, '\t') + "---" + getName() + '\n';
}

void Warrior::setTactic(std::shared_ptr<Tactic> value) {
    if (value->includes(shared_from_this())) {
        tactic = std::move(value);
    }
}

int Warrior::getSkillLevel() {
    return skillLevel;
}

int Warrior::getEquipmentLevel() {
    return equipmentLevel;
}

bool Warrior::isWarrior() {
    return true;
}