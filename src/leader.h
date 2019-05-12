#include <utility>

//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_LEADER_H
#define GAME_LEADER_H

#include <string>
#include "squad.h"
#include "Kingdom.h"
#include "army.h"
#include <memory>
#include <memory>

class Leader : public std::enable_shared_from_this<Leader> {
private:
    std::string Name = "";
    Kingdom kingdom;
    int honor = 0;
    int strategic = 0;
    int charisma = 0;
    int coaching = 0;
    std::shared_ptr <Army> army = nullptr;

    void setUpName();
    void setUpKingdom();
    void setUpCharacteristic();
    int getMaxChar();
public:
    Leader() = default;
    Leader(std::string Name, Kingdom kingdom, int honor, int strategic, int charisma, int coaching) : Name(
            std::move(Name)), kingdom(kingdom), honor(honor), strategic(strategic), charisma(charisma),
            coaching(coaching) {
        this->kingdom = kingdom;
    }

    std::string getName();
    void setByUser();
    Kingdom getKingdom();
    std::string getArmyInfo();
    void reorganizeArmy();
    bool payForArmy();
    bool foodForArmy();
    int getArmyCost();
    int getUnpayedWeeks();
    int getMoney();
    void setArmy(std::shared_ptr<Army> army_);
    void payArmy(int weeks);
    void increaseUnpayedWeeks();
    int getCanCarry();
    int getFood();
    int getHonor();
    int getStrategic();
    int getCharisma();
    int getCoaching();
    void decreaseMoney(int value);
    void train();
    void buyEquipment();
    std::shared_ptr<Army> getArmy();
    void addWarrior(std::shared_ptr<Warrior> warrior);
    int getFoodCnt();
    void addFood(int value);
    void addHonor(int value);
};

#endif //GAME_LEADER_H
