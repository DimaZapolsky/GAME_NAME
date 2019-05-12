//
// Created by Dima Zapolsky on 10/05/2019.
//

#ifndef GAME_SQUAD_H
#define GAME_SQUAD_H

#include <vector>

#include "tactic.h"
#include <sstream>
class Warrior;
#include <vector>
#include <memory>

class Squad : public std::enable_shared_from_this<Warrior> {
protected:
    std::vector <std::shared_ptr<Squad> > children;
    int depth = 0;
    void setDepth(int value);
    int getDepth();
    std::string Name;
    std::shared_ptr<Tactic> tactic;
public:
    virtual ~Squad() {}
    Squad() = default;
    virtual int getFood() const;
    virtual int getCost() const;
    virtual int getCanCarry() const;
    void add(std::shared_ptr<Squad> squad);
    virtual void setTactic(std::shared_ptr<Tactic> value);
    void setName(std::string Name_);
    std::shared_ptr<Tactic> getTactic();
    virtual std::vector <std::shared_ptr<Warrior> > getAllWarriors();
    std::string getName();
    virtual std::string getInfo();
    int getChildrenSize();
    std::shared_ptr<Squad> getNthChild(int n);
    void clearSquad();
    bool isWarrior();
};

#endif //GAME_SQUAD_H
