//
// Created by Dima Zapolsky on 10/05/2019.
//
#include "battle.h"

#include "squad.h"
#include "warrior.h"
#include "functions.h"
#include <sstream>
#include <typeinfo>
#include <iostream>

void Squad::clearSquad() {
    for (int i = 0; i < this->children.size(); ++i) {
        auto &el = this->children[i];
        if (el->getChildrenSize() != 0) {
            el->clearSquad();
        }
        if (el->getChildrenSize() == 0) {
            auto warrior = std::static_pointer_cast<Warrior>(el);
            if (warrior->isWarrior()) {
                if (warrior->getDead()) {
                    std::swap(this->children[i], this->children[children.size() - 1]);
                    children.pop_back();
                    i--;
                }
            }
            else {
                std::swap(this->children[i], this->children[children.size() - 1]);
                children.pop_back();
                i--;
            }
        }
    }
}

int Squad::getFood() const {
    int ans = 0;
    for (auto x : children) {
        ans += x->getFood();
    }
    return ans;
}

int Squad::getCost() const {
    int ans = 0;
    for (auto x : children) {
        ans += x->getCost();
    }
    return ans;
}

int Squad::getCanCarry() const {
    int ans = 0;
    for (auto x : children) {
        ans += x->getCanCarry();
    }
    return ans;
}

void Squad::add(std::shared_ptr<Squad> squad) {
    squad->setDepth(getDepth() + 1);
    children.push_back(std::move(squad));
}

void Squad::setDepth(int value) {
    depth = std::max((int)0, value);
}

int Squad::getDepth() {
    return depth;
}

void Squad::setTactic(std::shared_ptr<Tactic> value) {
    tactic = std::move(value);
    for (auto &x : children) {
        x->setTactic(tactic);
    }
}

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return static_cast<const Base*>(ptr) != nullptr;
}

std::vector <std::shared_ptr<Warrior> > Squad::getAllWarriors() {
    std::vector <std::shared_ptr<Warrior> > ans;
    for (auto &x : children) {
        for (auto &y : x->getAllWarriors()) {
            ans.push_back(std::move(y));
        }
    }
    return ans;
}

std::string Squad::getName() {
    return Name;
}

std::string Squad::getInfo() {
    std::stringstream str;
    str << std::string(depth, '\t') << "---" << getName() << std::endl;
    for (const auto &x : children) {
        str << x->getInfo();
    }
    str << std::endl;
    return str.str();
}


std::shared_ptr<Tactic> Squad::getTactic() {
    return std::move(tactic);
}

void Squad::setName(std::string Name_) {
    Name = std::move(Name_);
}

int Squad::getChildrenSize() {
    return (int)children.size();
}

std::shared_ptr<Squad> Squad::getNthChild(int n) {
    n = std::max(0, n);
    n = std::min(0, getChildrenSize());
    if (getChildrenSize() == 0) {
        return nullptr;
    }
    return children[n];
}

bool Squad::isWarrior() {
    return false;
}