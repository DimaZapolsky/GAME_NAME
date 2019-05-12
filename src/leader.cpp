#include <utility>

//
// Created by Dima Zapolsky on 09/05/2019.
//

#include <iostream>
#include "leader.h"
#include "game.h"
#include "functions.h"
#include <algorithm>

std::string Leader::getName() {
    return this->Name;
}

int Leader::getHonor() {
    return honor;
}

Kingdom Leader::getKingdom() {
    return kingdom;
}

void Leader::setUpName() {
    std::cout << "Введите имя персонажа" << std::endl;
    std::string s;
    while (s.empty()) {
        getline(std::cin, s);
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }
        std::reverse(s.begin(), s.end());
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }
        std::reverse(s.begin(), s.end());
    }
    Name = s;
}

void Leader::setUpKingdom() {
    std::cout << "Введите королевство за которое хотите играть (R/r - Равенстерн, S/s - Сарлеон)" << std::endl;
    std::string s;
    while (std::cin >> s && strip(s) && tolower(s) && s.size() > 0 && s[0] != 'r' && s[0] != 's') {
        std::cout << "Что-то на эльфийском, не могу разобрать. Введите, пожалуйста, еще раз" << std::endl;
    }
    if (s[0] == 'r') {
        kingdom = Kingdom::Ravenstern;
    }
    else if (s[0] == 's') {
        kingdom = Kingdom ::Sarleon;
    }
}

int Leader::getMaxChar() {
    int hardness = Game::getInstance()->getHardness();
    switch (hardness) {
        case 0:
            return 20;
        case 1:
            return 15;
        case 2:
            return 10;
        default:
            return 15;
    }
}

void Leader::setUpCharacteristic() {
    std::cout << "Введите 3 числа (cтратегичность, харизма и тренерство) (их сумма должна равнятся " << getMaxChar() << ")" << std::endl;
    while (std::cin >> strategic >> charisma >> coaching && (strategic + charisma + coaching != getMaxChar() || strategic < 0 || charisma < 0 || coaching < 0)) {
        std::cout << "Что-то не сходится, попробуйте еще раз" << std::endl;
    }
}

void Leader::setByUser() {
    setUpName();
    setUpKingdom();
    setUpCharacteristic();
    army = std::move(std::shared_ptr<Army>(new Army()));
    army->setLeader(shared_from_this());
    army->setMoney(500 * (4 - Game::getInstance()->getHardness()));
    army->setArmy(std::shared_ptr<Squad>(new Squad()));
    army->getArmy()->setName("Армия");
}

std::string Leader::getArmyInfo() {
    return army->getInfo();
}

void Leader::reorganizeArmy() {
    army->reorganize();
}

bool Leader::payForArmy() {
    return army->pay();
}

bool Leader::foodForArmy() {
    return army->eat();
}

int Leader::getArmyCost() {
    return army->getCost();
}

int Leader::getUnpayedWeeks() {
    return army->getUnpayedWeeks();
}

int Leader::getMoney() {
    return army->getMoney();
}

void Leader::payArmy(int weeks) {
    army->decreaseUnpayedWeeks(weeks);
    army->decreaseMoney(weeks * army->getCost());
}

void Leader::increaseUnpayedWeeks() {
    army->increaseUnpayedWeeks();
}

int Leader::getCanCarry() {
    return army->getCanCarry();
}

int Leader::getFood() {
    return army->getFood();
}

int Leader::getCharisma() {
    return charisma;
}

int Leader::getStrategic() {
    return strategic;
}

int Leader::getCoaching() {
    return coaching;
}

void Leader::decreaseMoney(int value) {
    army->decreaseMoney(value);
}

void Leader::train() {
    army->train(getCoaching());
}

void Leader::buyEquipment() {
    army->buyEquipment(charisma);
}

std::shared_ptr<Army> Leader::getArmy() {
    return army;
}

void Leader::addWarrior(std::shared_ptr<Warrior> warrior) {
    army->addWarrior(std::move(warrior));
}

int Leader::getFoodCnt() {
    return army->getFoodCnt();
}

void Leader::addFood(int value) {
    army->addFood(value);
}

void Leader::addHonor(int value) {
    honor += value;
}

void Leader::setArmy(std::shared_ptr<Army> army_) {
    army = std::move(army_);
}