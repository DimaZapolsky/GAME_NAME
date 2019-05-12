//
// Created by Dima Zapolsky on 09/05/2019.
//

#include <cmath>
#include "horseman.h"
#include "../battle.h"

double Horseman::calculate_strength(terrainEnum terrain) const {
    double terrain_mult = 4;
    double armor_char = std::pow(std::pow(std::min(getHorseArmor(), getArmor()), 0.7) * std::pow(std::max(getHorseArmor(), getArmor()), 0.3), 1.8);
    double mobility_char = 0;
    double attack_defense = getDamage();
    if (terrain == terrainEnum::mountains) {
        mobility_char = std::pow(getMobility(), 0.7) * std::pow(getHorseSpeed(), 0.3);
        mobility_char = std::pow(mobility_char, 2);
        attack_defense = std::pow(attack_defense, 1.2);
    } else {
        mobility_char = std::pow(getHorseSpeed(), 0.7) * std::pow(getMobility(), 0.3);
        mobility_char = std::pow(mobility_char, 1.4);
        attack_defense = std::pow(attack_defense, 1.8);
    }

    return mobility_char * attack_defense * armor_char / (terrain == terrainEnum::plain ? 1 : terrain_mult);
}

/*
double Horseman::getChance(Battle battle, std::shared_ptr<Warrior> enemy) const {
    return 0.5;
}

 */

int Horseman::getDamage() const {
    return damage[std::min((int)damage.size() - 1, equipmentLevel + skillLevel)];
}

int Horseman::getHorseArmor() const {
    return horseArmor[std::min((int)horseArmor.size() - 1, equipmentLevel)];
}

int Horseman::getHorseSpeed() const {
    return horseSpeed[std::min((int)horseSpeed.size() - 1, equipmentLevel)];
}

int Horseman::getArmor() const {
    return armor[std::min((int)armor.size() - 1, equipmentLevel)];
}

int Horseman::getMobility() const {
    return mobility[std::min((int)mobility.size() - 1, skillLevel)];
}

WarriorType Horseman::getType() const {
    return THorseman;
}