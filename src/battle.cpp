//
// Created by Dima Zapolsky on 09/05/2019.
//

#include <iostream>
#include "battle.h"
#include "functions.h"
#include "game.h"
#include <map>

void Battle::addSubscriber(std::shared_ptr<IEndBattleObserver> subscriber) {
    this->subscribers.push_back(subscriber);
}

void Battle::notifyOnBattleEnded() {
    for (auto &subscriber : subscribers) {
        subscriber->battleHasEnded();
    }
}

void Battle::disposeSubscriptions() {
    subscribers.clear();
}

terrainEnum Battle::getTerrain() const {
    return terrain;
}

Battle::Battle(std::vector<std::shared_ptr<Army>> &squads, std::shared_ptr<IBattle_logger> &logger) {
    this->squads = squads;
    this->logger = logger;

    for (auto &army : squads) {
        subscribers.push_back(army);
    }
}

int Battle::get_ticks() const {
    return this->tick;
}

void Battle::setTactics() {
    auto army = Game::getInstance()->getPlayer()->getArmy();
    while (true) {
        std::cout << "Введите что вы хотите сделать (-1 - начать бой, 0 - информация об армии, 1 - добавить приказ)" << std::endl;
        int a;
        while (std::cin >> a) {
            if (a < -1 || a > 1) {
                std::cout << "Такого варианта нет:(" << std::endl;
            }
            else {
                break;
            }
        }
        if (a == -1) {
            break;
        }
        else if (a == 0) {
            std::cout << army->getInfo() << std::endl;
        }
        else {
            army->addTactic();
        }
    }
}

std::vector<std::shared_ptr<IBattle_log>> Battle::start_war(bool should_log_to_console) {
    setTactics();
    this->addSubscriber(this->logger);

    std::vector<std::vector<std::shared_ptr<Warrior>>> allWarriors;
    allWarriors.push_back(std::vector<std::shared_ptr<Warrior>>());
    allWarriors.push_back(std::vector<std::shared_ptr<Warrior>>());

    int enemyMoney = 0;
    int enemyFood = 0;
    int enemyHonor = 0;
    Kingdom playerKingdom = Game::getInstance()->getPlayer()->getKingdom();
    for (auto &army : this->squads) {
        if (army->getLeader()->getKingdom() != playerKingdom) {
            enemyFood += army->getFoodCnt();
            enemyMoney += army->getMoney();
            enemyHonor += army->getLeader()->getHonor();
        }
        for (std::shared_ptr<Warrior> const &warrior : army->getArmy()->getAllWarriors()) {
            allWarriors[getTeam(warrior)].push_back(warrior);
        }
    }

    int totalWarriors = allWarriors[0].size() + allWarriors[1].size();

    std::map<Kingdom, int> deadCount;
    int totalDeadCount = 0;

    while (totalDeadCount < totalWarriors && (allWarriors[0].size() >= 1 &&  allWarriors[1].size() >= 1)) {
        int first_warrior_index = rand() % (allWarriors[Sarleon].size());
        int second_warrior_index = rand() % (allWarriors[Ravenstern].size());

        if (first_warrior_index == second_warrior_index) {
            continue;
        }

        if (allWarriors[0][first_warrior_index]->getTactic() != nullptr && !allWarriors[0][first_warrior_index]->getTactic()->canAttack(allWarriors[1][second_warrior_index])) {
            continue;
        }

        tick++;

        auto first_warrior = allWarriors[Sarleon][first_warrior_index];
        auto second_warrior = allWarriors[Ravenstern][second_warrior_index];

        double first_win_chance = first_warrior->getChance(*this, second_warrior);
        double second_win_chance = second_warrior->getChance(*this, first_warrior);

        int random_max = (int)1e8;
        int first_rand = rand() % random_max;
        int second_rand = rand() % random_max;

        if (first_rand < first_win_chance * random_max / (first_win_chance + second_win_chance)) {
            second_warrior->setDead(true);
            std::swap(allWarriors[Ravenstern][second_warrior_index], allWarriors[Ravenstern][allWarriors[Ravenstern].size() - 1]);
            allWarriors[Ravenstern].pop_back();
            deadCount[Ravenstern]++;

            auto new_log = Battle_log(second_warrior, first_warrior, tick);
            logger->addLog(std::make_shared<Battle_log>(new_log));
        }

        if (second_rand < second_win_chance * random_max / (first_win_chance + second_win_chance)) {
            first_warrior->setDead(true);
            std::swap(allWarriors[Sarleon][first_warrior_index], allWarriors[Sarleon][allWarriors[Sarleon].size() - 1]);
            allWarriors[Sarleon].pop_back();
            deadCount[Sarleon]++;

            auto new_log = Battle_log(first_warrior, second_warrior, tick);
            logger->addLog(std::make_shared<Battle_log>(new_log));
        }
    }
    if (should_log_to_console) {
        std::cout << "Военная сводка:\n" + logger->getStringLogs();
    }
    Kingdom winner;
    if (allWarriors[0].size() > 0) {
        winner = Sarleon;
    }
    else {
        winner = Ravenstern;
    }
    if (winner == Ravenstern) {
        std::cout << "Равенстерн победил" << std::endl;
    }
    else {
        std::cout << "Сарлеон победил" << std::endl;
    }
    if (winner == playerKingdom) {
        std::cout << "Вы получили: " << std::endl;
        int earnedMoney = enemyMoney * (90 + rand() % 11) / 100;
        int earnedFood = enemyFood * (70 + rand() % 31) / 100;
        int earnedHonor = enemyHonor * (10 + rand() % 16) / 100;
        std::cout << earnedMoney << " монет" << std::endl;
        Game::getInstance()->getPlayer()->getArmy()->addMoney(earnedMoney);
        std::cout << earnedFood << " еды" << std::endl;
        Game::getInstance()->getPlayer()->getArmy()->addFood(earnedFood);
        std::cout << earnedHonor << " чести" << std::endl;
        Game::getInstance()->getPlayer()->addHonor(earnedHonor);
    }
    else {
        std::cout << "Вы проиграли эту битву, но не войну!!!!!" << std::endl;
    }
    this->notifyOnBattleEnded();
    this->disposeSubscriptions();
    return logger->getLogs();
}

void Battle::start_war_test() {
    this->addSubscriber(this->logger);

    std::vector<std::vector<std::shared_ptr<Warrior>>> allWarriors;
    allWarriors.push_back(std::vector<std::shared_ptr<Warrior>>());
    allWarriors.push_back(std::vector<std::shared_ptr<Warrior>>());

    for (auto &army : this->squads) {
        for (std::shared_ptr<Warrior> const &warrior : army->getArmy()->getAllWarriors()) {
            allWarriors[getTeam(warrior)].push_back(warrior);
        }
    }

    int totalWarriors = allWarriors[0].size() + allWarriors[1].size();

    std::map<Kingdom, int> deadCount;
    int totalDeadCount = 0;

    while (totalDeadCount < totalWarriors && (allWarriors[0].size() >= 1 &&  allWarriors[1].size() >= 1)) {
        int first_warrior_index = rand() % (allWarriors[Sarleon].size());
        int second_warrior_index = rand() % (allWarriors[Ravenstern].size());

        if (first_warrior_index == second_warrior_index) {
            continue;
        }

        if (allWarriors[0][first_warrior_index]->getTactic() != nullptr && !allWarriors[0][first_warrior_index]->getTactic()->canAttack(allWarriors[1][second_warrior_index])) {
            continue;
        }

        tick++;

        auto first_warrior = allWarriors[Sarleon][first_warrior_index];
        auto second_warrior = allWarriors[Ravenstern][second_warrior_index];

        double first_win_chance = first_warrior->getChance(*this, second_warrior);
        double second_win_chance = second_warrior->getChance(*this, first_warrior);

        int random_max = (int)1e8;
        int first_rand = rand() % random_max;
        int second_rand = rand() % random_max;

        if (first_rand < first_win_chance * random_max / (first_win_chance + second_win_chance)) {
            second_warrior->setDead(true);
            std::swap(allWarriors[Ravenstern][second_warrior_index], allWarriors[Ravenstern][allWarriors[Ravenstern].size() - 1]);
            allWarriors[Ravenstern].pop_back();
            deadCount[Ravenstern]++;

            auto new_log = Battle_log(second_warrior, first_warrior, tick);
            logger->addLog(std::make_shared<Battle_log>(new_log));
        }

        if (second_rand < second_win_chance * random_max / (first_win_chance + second_win_chance)) {
            first_warrior->setDead(true);
            std::swap(allWarriors[Sarleon][first_warrior_index], allWarriors[Sarleon][allWarriors[Sarleon].size() - 1]);
            allWarriors[Sarleon].pop_back();
            deadCount[Sarleon]++;

            auto new_log = Battle_log(first_warrior, second_warrior, tick);
            logger->addLog(std::make_shared<Battle_log>(new_log));
        }
    }
    this->notifyOnBattleEnded();
    this->disposeSubscriptions();
}


