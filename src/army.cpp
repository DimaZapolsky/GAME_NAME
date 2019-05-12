//
// Created by Dima Zapolsky on 10/05/2019.
//

#include <random>
#include "army.h"
#include <typeinfo>
#include <map>
#include <vector>
#include <iostream>
#include "warrior.h"
#include "warriorType.h"
#include "functions.h"
#include <algorithm>
#include "sstream"
#include "leader.h"

void Army::battleHasEnded() {
    //clean up
    this->army->clearSquad();
}

void Army::setArmy(std::shared_ptr<Squad> army_) {
    army = std::move(army_);
}

void Army::setLeader(std::shared_ptr<Leader> leader_) {
    leader = std::move(leader_);
}

std::shared_ptr<Leader> Army::getLeader() {
    return leader;
}

std::shared_ptr<Squad> Army::getArmy() {
    return army;
}

std::string Army::getStructure() {
    return army->getInfo();
}

std::string Army::getMainChar() {
    std::ostringstream str;
    str << "Стоимость: " << army->getCost() << std::endl;
    str << "Потребление еды: " << army->getFood() << std::endl;
    str << "Переносимый вес: " << army->getCanCarry() << std::endl;
    str << "Еды: " << food << std::endl;
    str << "Денег: " << money << std::endl;
    return str.str();
}

std::string Army::getInfo() {
    return getStructure() + getMainChar();
}

void Army::reorganize() {
    auto warriors = army->getAllWarriors();
    army = std::shared_ptr<Squad>(new Squad());
    army->setName("Армия");
    std::map <WarriorType, std::vector <std::shared_ptr<Warrior> > > mapa;
    for (auto x : warriors) {
        mapa[x->getType()].push_back(x);
    }
    std::cout << "Введите количество отрядов, на которые вы хотите разбить армию (0 - не разбивать на отряды)" << std::endl;
    int cnt_of_squads;
    while (std::cin >> cnt_of_squads && (cnt_of_squads < 0 || cnt_of_squads > warriors.size())) {
        std::cout << "Что-то не то. Попробуйте еще раз" << std::endl;
    }
    if (cnt_of_squads == 0) {
        for (auto x : warriors) {
            army->add(x);
        }
        std::cout << "Новая структура армии:" << std::endl;
        std::cout << getStructure() << std::endl;
        return;
    }
    std::shuffle(mapa[TArcher].begin(), mapa[TArcher].end(), std::mt19937(std::random_device()()));
    std::shuffle(mapa[THorseman].begin(), mapa[THorseman].end(), std::mt19937(std::random_device()()));
    std::shuffle(mapa[TInfantryman].begin(), mapa[TInfantryman].end(), std::mt19937(std::random_device()()));
    for (int i = 0; i < cnt_of_squads; ++i) {
        auto squad = std::shared_ptr<Squad>(new Squad());
        std::cout << "Свободных лучников: " << mapa[TArcher].size() << std::endl;
        std::cout << "Свободных кавалеристов: " << mapa[THorseman].size() << std::endl;
        std::cout << "Свободных пехотинцев: " << mapa[TInfantryman].size() << std::endl;
        std::cout << "Введите название отряда" << std::endl;
        std::string s;
        while (getline(std::cin, s)) {
            strip(s);
            if (s.size() != 0)
                break;
        }
        squad->setName(s);
        std::cout << "Введите количество воинов каждого типа (лучники, конница, пехота)" << std::endl;
        int archer, horseman, infantryman;
        while (std::cin >> archer >> horseman >> infantryman) {
            if (archer < 0 || horseman < 0 || infantryman < 0) {
                std::cout << "Что-то не так. Попробуйте еще раз" << std::endl;
                continue;
            }
            if (archer > mapa[TArcher].size() || horseman > mapa[THorseman].size() || infantryman > mapa[TInfantryman].size()) {
                std::cout << "Что-то не так. Попробуйте еще раз" << std::endl;
                continue;
            }
            break;
        }
        army->add(squad);
        for (int j = 0; j < archer; ++j) {
            squad->add(mapa[TArcher].back());
            mapa[TArcher].pop_back();
        }
        for (int j = 0; j < infantryman; ++j) {
            squad->add(mapa[TInfantryman].back());
            mapa[TInfantryman].pop_back();
        }
        for (int j = 0; j < horseman; ++j) {
            squad->add(mapa[THorseman].back());
            mapa[THorseman].pop_back();
        }
    }
    for (auto x : mapa[TArcher]) {
        army->add(x);
    }
    for (auto x : mapa[TInfantryman]) {
        army->add(x);
    }
    for (auto x : mapa[THorseman]) {
        army->add(x);
    }
    std::cout << "Новая структура армии:" << std::endl;
    std::cout << getStructure() << std::endl;
}

bool Army::pay() {
    if (unpayedWeeks > 0) {
        std::cout << "Вы задолжали армии за " << unpayedWeeks << " недель!!!" << std::endl;
    }
    if (unpayedWeeks > 4) {
        return true;
    }
    return false;
}

bool Army::eat() {
    if (food >= army->getFood()) {
        food -= army->getFood();
        daysWOFood = 0;
        return false;
    }
    else {
        daysWOFood++;
        std::cout << "Ваша армия без еды уже " << daysWOFood << " дней" << std::endl;
        return daysWOFood > 5;
    }
}

int Army::getUnpayedWeeks() {
    return unpayedWeeks;
}

int Army::getDaysWOFood() {
    return daysWOFood;
}

void Army::decreaseUnpayedWeeks(int value) {
    unpayedWeeks -= value;
}

int Army::getCost() {
    return army->getCost();
}

int Army::getMoney() {
    return money;
}

void Army::decreaseMoney(int value) {
    money -= value;
}

void Army::increaseUnpayedWeeks() {
    if (getCost() > 0)
        unpayedWeeks++;
    else
        unpayedWeeks = 0;
}

int Army::getCanCarry() {
    return army->getCanCarry();
}

int Army::getFood() {
    return army->getFood();
}

int Army::getFoodCnt() {
    return food;
}

void Army::train(int coaching) {
    auto warriors = army->getAllWarriors();
    int cnt2 = 0;
    for (auto x : warriors) {
        if (x->getSkillLevel() < 4) {
            cnt2++;
        }
    }
    if (cnt2 == 0) {
        std::cout << "У вас нет воинов, которых можно тренировать(((" << std::endl;
        return;
    }
    std::cout << "Введите кого вы хотите тренировать (лучник - A/a, пехотинец - I/i, кавалерист - H/h)" << std::endl;
    char c;
    WarriorType wanted;
    std::map <WarriorType, int> cnt;
    for (auto x : warriors) {
        if (x->getSkillLevel() < 4)
            cnt[x->getType()]++;
    }
    while (std::cin >> c) {
        c = tolower(c);
        if (c == 'a') {
            if (cnt[TArcher] == 0) {
                std::cout << "У вас нет лучников, которых можно тренировать" << std::endl;
            }
            else {
                wanted = TArcher;
                break;
            }
        }
        else if (c == 'i') {
            if (cnt[TInfantryman] == 0) {
                std::cout << "У вас нет пехотинцев, которых можно тренировать" << std::endl;
            }
            else {
                wanted = TInfantryman;
                break;
            }
        }
        else if (c == 'h') {
            if (cnt[THorseman] == 0) {
                std::cout << "У вас нет конницы, которых можно тренировать" << std::endl;
            }
            else {
                wanted = THorseman;
                break;
            }
        }
        else {
            std::cout << "Что-то на эльфийском, не могу разобрать... Попробуйте еще раз" << std::endl;
        }
    }
    int canCoach = coaching + 1;
    std::vector <std::shared_ptr<Warrior> > wantedArr;
    int mx = 0;
    for (auto x : warriors) {
        if (x->getType() == wanted && x->getSkillLevel() < 4) {
            mx += 4 - x->getSkillLevel();
            wantedArr.push_back(std::move(x));
        }
    }
    canCoach = std::min(canCoach, mx);
    while (canCoach > 0) {
        int i = rand() % wantedArr.size();
        wantedArr[i]->upSkillLevel();
        if (wantedArr[i]->getSkillLevel() == 4) {
            wantedArr.erase(wantedArr.begin() + i);
        }
        canCoach--;
    }
    std::cout << "Тренировка закончена" << std::endl;
    while (warriors.size() > 0) {
        warriors.pop_back();
    }
    while (wantedArr.size() > 0) {
        wantedArr.pop_back();
    }
}

void Army::buyEquipment(int charisma) {
    auto warriors = army->getAllWarriors();
    int cnt2 = 0;
    for (auto x : warriors) {
        if (x->getEquipmentLevel() < 4)
            cnt2++;
    }
    if (cnt2 == 0) {
        std::cout << "У вас нет воинов, которым можно улучшить снаряжение((" << std::endl;
        return;
    }
    std::cout << "Введите для кого вы хотите купить снаряжение (лучник - A/cnt_of_equipment, пехотинец - I/i, кавалерист - H/h)" << std::endl;
    char c;
    WarriorType wanted;
    std::map <WarriorType, int> cnt;
    for (auto x : warriors) {
        if (x->getEquipmentLevel() < 4) {
            cnt[x->getType()]++;
        }
    }
    while (std::cin >> c) {
        c = tolower(c);
        if (c == 'a') {
            if (cnt[TArcher] == 0) {
                std::cout << "У вас нет лучников, которым можно улучшить снаряжение" << std::endl;
            }
            else {
                wanted = TArcher;
                break;
            }
        }
        else if (c == 'i') {
            if (cnt[TInfantryman] == 0) {
                std::cout << "У вас нет пехотинцев, которым можно улучшить снаряжение" << std::endl;
            }
            else {
                wanted = TInfantryman;
                break;
            }
        }
        else if (c == 'h') {
            if (cnt[THorseman] == 0) {
                std::cout << "У вас нет кавалеристов, которым можно улучшить снаряжение" << std::endl;
            }
            else {
                wanted = THorseman;
                break;
            }
        }
        else {
            std::cout << "Что-то на эльфийском, не могу разобрать... Попробуйте еще раз" << std::endl;
        }
    }
    int equipmentCost = 16 - charisma;
    int max_can_buy = money / equipmentCost;
    int mx = 0;
    std::vector<std::shared_ptr<Warrior> > wantedArr;
    for (auto x : warriors) {
        if (x->getType() == wanted && x->getEquipmentLevel() < 4) {
            mx += 4 - x->getEquipmentLevel();
            wantedArr.push_back(std::move(x));
        }
    }
    int cnt_of_equipment;
    max_can_buy = std::min(max_can_buy, mx);
    std::cout << "Вы можете купить максимум " << max_can_buy << " снаряжений" << std::endl;
    while (std::cin >> cnt_of_equipment) {
        if (cnt_of_equipment < 0 || cnt_of_equipment > max_can_buy) {
            std::cout << "Что-то не так. Попробуйте еще раз" << std::endl;
        }
        else {
            break;
        }
    }
    money -= cnt_of_equipment * equipmentCost;
    while (cnt_of_equipment > 0) {
        int i = rand() % wantedArr.size();
        wantedArr[i]->upEquipmentLevel();
        if (wantedArr[i]->getEquipmentLevel() == 4) {
            wantedArr.erase(wantedArr.begin() + i);
        }
        cnt_of_equipment--;
    }
    std::cout << "Снаряжение куплено" << std::endl;
}

void Army::addTactic() {
    std::cout << "Введите порядковый номер отряда, которому хотите отдать приказ (все отряды = 0)" << std::endl;
    int squad;
    int squads = army->getChildrenSize();
    while (std::cin >> squad) {
        if (squad < 0 || squad > squads) {
            std::cout << "Что-то не так. Попробуйте еще раз" << std::endl;
        }
        else {
            break;
        }
    }

    std::cout << "Кому вы хотите отдать команду? (Лучники - A/a, Конница - H/h, Пехота - I/i, Все - all)" << std::endl;
    std::string s;
    Tactic::TacticWarrior warrior;
    while (std::cin >> s) {
        tolower(s);
        if (s == "all") {
            warrior = Tactic::all;
            break;
        }
        else if (s[0] == 'a') {
            warrior = Tactic::Archer;
            break;
        }
        else if (s[0] == 'h') {
            warrior = Tactic::Horseman;
            break;
        }
        else if (s[0] == 'i') {
            warrior = Tactic::Infantryman;
            break;
        }
        else {
            std::cout << "Что-то на эльфийском, не могу разобрать. Попробуйте еще раз" << std::endl;
        }
    }

    std::cout << "Какую команду вы хотите отдать атаковать или защищаться (a / d)" << std::endl;
    char c;
    Tactic::TacticAction actionType;
    while (std::cin >> c) {
        c = tolower(c);
        if (c == 'a') {
            actionType = Tactic::Attack;
            break;
        }
        else if (c == 'd') {
            actionType = Tactic::Defense;
            break;
        }
        else {
            std::cout << "Что-то на эльфийском, не могу разобрать. Попробуйте еще раз" << std::endl;
        }
    }
    Tactic::TacticWarrior target;
    Tactic::AttackType attackType;
    if (actionType == Tactic::Attack) {
        std::cout << "Кому вы хотите атаковать? (Лучники - A/a, Конница - H/h, Пехота - I/i, Все - all)" << std::endl;
        std::string s;
        while (std::cin >> s) {
            tolower(s);
            if (s == "all") {
                target = Tactic::all;
                break;
            }
            else if (s[0] == 'a') {
                target = Tactic::Archer;
                break;
            }
            else if (s[0] == 'h') {
                target = Tactic::Horseman;
                break;
            }
            else if (s[0] == 'i') {
                target = Tactic::Infantryman;
                break;
            }
            else {
                std::cout << "Что-то на эльфийском, не могу разобрать. Попробуйте еще раз" << std::endl;
            }
        }

        std::cout << "Как вы хотите атаковать в фронта или с тыла (Фронт - F/f, Тыл - R/r)" << std::endl;
        char c;
        while (std::cin >> c) {
            c = tolower(c);
            if (c == 'f') {
                attackType = Tactic::Front;
                break;
            }
            else if (c == 'r') {
                attackType = Tactic::Rear;
                break;
            }
            else {
                std::cout << "Что-то на эльфийском, не могу разобрать. Попробуйте еще раз" << std::endl;
            }
        }
    }

    std::shared_ptr<Tactic> new_tactic(new Tactic(warrior, actionType, attackType, target));
    if (squad == 0) {
        army->setTactic(new_tactic);
    }
    else {
        auto squadPtr = army->getNthChild(squad - 1);
        squadPtr->setTactic(new_tactic);
    }
    std::cout << "Приказ отдан" << std::endl;
}

void Army::addWarrior(std::shared_ptr<Warrior> warrior) {
    army->add(warrior);
}

void Army::setMoney(int value) {
    money = value;
}

void Army::addFood(int value) {
    food += value;
    food = std::min(food, army->getCanCarry());
}

void Army::addMoney(int value) {
    money += value;
}