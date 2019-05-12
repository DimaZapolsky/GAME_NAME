//
// Created by Dima Zapolsky on 2019/05/11.
//

#ifndef GAME_BATTLEFACTORY_H
#define GAME_BATTLEFACTORY_H


#include <memory>
#include "Logger/battle_logger.h"
#include "battle.h"

//Create this instance, call createBattle
class BattleFactory {
private:
    std::shared_ptr<IBattle_logger> logger;
public:
    BattleFactory();
    std::shared_ptr<IBattle> createBattle(std::vector<std::shared_ptr<Army>> &armies);
};


#endif //GAME_BATTLEFACTORY_H
