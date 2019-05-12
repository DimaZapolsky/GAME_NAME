//
// Created by Dima Zapolsky on 09/05/2019.
//

#include <cmath>
#include "infantryman.h"
#include "../battle.h"

double Infantryman::calculate_strength(terrainEnum terrain) const {
    double terrain_mult = 2.5;
    double without_shield_divisour = 2.5;
    double without_shield = pow(getDamage(), 1.5) * pow(getArmor(), 1.8) * pow(getSpeed(), 1.7) / without_shield_divisour;
    return (getHaveShield()? without_shield * without_shield_divisour : without_shield) /
            (terrain == terrainEnum::plain ? 1 : terrain_mult);
}

/*
double Infantryman::getChance(Battle battle, std::shared_ptr<Warrior> enemy) const {
    return 0.5;
}
 */

int Infantryman::getDamage() const {
    return damage[std::min((int)damage.size() - 1, equipmentLevel + skillLevel)];
}

int Infantryman::getArmor() const {
    return armor[std::min((int)armor.size() - 1, equipmentLevel)];
}

int Infantryman::getHaveShield() const {
    return haveShield[std::min((int)haveShield.size() - 1, equipmentLevel)];
}

int Infantryman::getSpeed() const {
    return speed[std::min((int)speed.size() - 1, skillLevel)];
}

WarriorType Infantryman::getType() const {
    return TInfantryman;
}
