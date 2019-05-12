//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_WARRIOR_H
#define GAME_WARRIOR_H

#include <vector>
#include "squad.h"
#include "warriorType.h"
#include "terrainEnum.h"
class Battle;

class Warrior : public Squad {
protected:
    bool dead = false;
    int skillLevel = 0;
    int equipmentLevel = 0;
    std::vector <int> canCarry;
    std::vector <int> food;
    std::vector <int> cost;
public:
    virtual ~Warrior() {};
    virtual double calculate_strength(terrainEnum terrain) const = 0;
    double getChance(Battle battle, std::shared_ptr<Warrior> enemy) const;
    void setDead(bool value);
    bool getDead() const;
    void upSkillLevel(bool show = true);
    void upEquipmentLevel(bool show = true);
    int getCanCarry() const override ;
    int getFood() const override ;
    int getCost() const override ;
    virtual std::string getName() const = 0;
    virtual WarriorType getType() const = 0;
    std::vector <std::shared_ptr<Warrior> > getAllWarriors() override;
    std::string getInfo() override;
    void setTactic(std::shared_ptr<Tactic> value) override;
    int getSkillLevel();
    int getEquipmentLevel();
    bool isWarrior();
};

#endif //GAME_WARRIOR_H
