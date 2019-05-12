//
// Created by Dima Zapolsky on 09/05/2019.
//

#include "archer.h"
#include "../battle.h"

double Archer::calculate_strength(terrainEnum terrain) const {
    double terrain_mult = 3;
    double without_terrain = (double)this->getAccuracy() * this->getAttackSpeed() * this->getDamage() * this->getMaxDistance()
           * this->getMaxDistance() / terrain_mult;
    if (terrain == terrainEnum::mountains) {
        return without_terrain * terrain_mult;
    }
    return without_terrain;
}

/*
double Archer::getChance(Battle battle, std::shared_ptr<Warrior> enemy) const {
    double max_strength = 1e10;
    return normed_probability_function(this->calculate_strength(battle.getTerrain()), enemy->calculate_strength(battle.getTerrain()), max_strength);
}
 */

int Archer::getAttackSpeed() const {
    return attackSpeed[std::min((int)attackSpeed.size() - 1, skillLevel)];
}

int Archer::getMaxDistance() const {
    return maxDistance[std::min((int)maxDistance.size() - 1, equipmentLevel + skillLevel)];
}

int Archer::getAccuracy() const {
    return accuracy[std::min((int)accuracy.size() - 1, skillLevel + equipmentLevel)];
}

int Archer::getDamage() const {
    return damage[std::min((int)accuracy.size() - 1, equipmentLevel)];
}

WarriorType Archer::getType() const {
    return TArcher;
}