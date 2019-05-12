//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_ARCHER_H
#define GAME_ARCHER_H

#include "../warrior.h"
#include <vector>

class Archer : public Warrior {
protected:
    std::vector <int> accuracy;
    std::vector <int> damage;
    std::vector <int> attackSpeed;
    std::vector <int> maxDistance;
public:
    virtual ~Archer() {};
    double calculate_strength(terrainEnum terrain) const override ;
    int getAccuracy() const;
    int getDamage() const ;
    int getAttackSpeed() const ;
    int getMaxDistance() const ;
    std::string getName() const override = 0;
    WarriorType getType() const;
};

#endif //GAME_ARCHER_H
