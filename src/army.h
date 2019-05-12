//
// Created by Dima Zapolsky on 10/05/2019.
//

#ifndef GAME_ARMY_H
#define GAME_ARMY_H

#include "squad.h"
#include "IEndBattleObserver.h"
#include <memory>

class Leader;

class Army : public IEndBattleObserver {
protected:
    std::shared_ptr<Squad> army = nullptr;
    std::shared_ptr<Leader> leader = nullptr;
    int food = 0;
    int money = 0;
    int unpayedWeeks = 0;
    int daysWOFood = 0;
public:
    Army() {};
    void battleHasEnded() override ;
    void setLeader(std::shared_ptr<Leader> leader_);
    void setArmy(std::shared_ptr<Squad> army_);
    std::shared_ptr<Leader> getLeader();
    std::shared_ptr<Squad> getArmy();
    std::string getInfo();
    std::string getStructure();
    std::string getMainChar();
    void reorganize();
    bool pay();
    bool eat();
    int getUnpayedWeeks();
    int getDaysWOFood();
    void decreaseUnpayedWeeks(int value);
    int getCost();
    int getMoney();
    void decreaseMoney(int value);
    void increaseUnpayedWeeks();
    int getCanCarry();
    int getFood();
    void train(int coaching);
    void buyEquipment(int charisma);
    void addTactic();
    void addWarrior(std::shared_ptr<Warrior> warrior);
    void setMoney(int value);
    int getFoodCnt();
    void addFood(int value);
    void addMoney(int value);
};

#endif //GAME_ARMY_H
