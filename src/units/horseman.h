//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_HORSEMAN_H
#define GAME_HORSEMAN_H

#include "../warrior.h"
#include <vector>

class Horseman : public Warrior {

protected:
    std::vector <int> horseArmor;
    std::vector <int> damage;
    std::vector <int> armor;
    std::vector <int> horseSpeed;
    std::vector <int> mobility;
public:
    virtual ~Horseman() {};
    double calculate_strength(terrainEnum terrain) const override ;
    //double getChance(Battle battle, std::shared_ptr<Warrior> enemy) const override;
    int getHorseArmor() const;
    int getDamage() const;
    int getArmor() const;
    int getHorseSpeed() const;
    int getMobility() const;
    std::string getName() const override = 0;
    WarriorType getType() const;
};

#endif //GAME_HORSEMAN_H
