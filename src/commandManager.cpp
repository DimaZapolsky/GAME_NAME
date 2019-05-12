//
// Created by Dima Zapolsky on 12/05/2019.
//

#include "commandManager.h"
#include "functions.h"
#include "game.h"

void CommandManager::start() {
    while (true) {
        std::string s;
        std::cin >> s;
        tolower(s);
        if (s == "help") {
            std::cout << "add - добавить воина в отряд" << std::endl;
            std::cout << "food - купить еду" << std::endl;
            std::cout << "pay - заплатить армии" << std::endl;
            std::cout << "equipment / eq - купить снаряжение для армии" << std::endl;
            std::cout << "train / tr - тренировать армию" << std::endl;
            std::cout << "reorganize / ro - реорганизация армии" << std::endl;
            std::cout << "info - информация о вашей армии" << std::endl;
            std::cout << "search / s - отправится в поиск приключений!!!" << std::endl;
            std::cout << "end - закончит игру" << std::endl;
        }
        else if (s == "add") {
            Game::getInstance()->addWarrior();
        }
        else if (s == "food") {
            Game::getInstance()->buyFood();
        }
        else if (s == "pay") {
            Game::getInstance()->payForArmy();
        }
        else if (s == "equipment" || s == "eq") {
            Game::getInstance()->buyEquipment();
        }
        else if (s == "train" || s == "tr") {
            Game::getInstance()->train();
        }
        else if (s == "reorganize" || s == "ro") {
            Game::getInstance()->reorganizeArmy();
        }
        else if (s == "info") {
            Game::getInstance()->getArmyInfo();
        }
        else if (s == "search" || s == "s") {
            Game::getInstance()->searchForEnemy();
        }
        else if (s == "end") {
            break;
        }
        else {
            std::cout << "Что-то на эльфийском, не могу разобрать." << std::endl;
        }
    }
}