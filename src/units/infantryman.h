//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_INFANTRYMAN_H
#define GAME_INFANTRYMAN_H

#include "../warrior.h"
#include <vector>

class Infantryman : public Warrior {
protected:
    std::vector <bool> haveShield;
    std::vector <int> damage;
    std::vector <int> armor;
    std::vector <int> speed;
public:
    virtual ~Infantryman() {};
    double calculate_strength(terrainEnum terrain) const override ;
    //double getChance(Battle battle, std::shared_ptr<Warrior> enemy) const override;
    int getHaveShield() const;
    int getDamage() const;
    int getArmor() const;
    int getSpeed() const;
    std::string getName() const override = 0;
    WarriorType getType() const;
};

#endif //GAME_INFANTRYMAN_H
