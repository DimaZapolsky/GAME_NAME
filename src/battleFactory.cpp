//
// Created by Dima Zapolsky on 2019/05/11.
//

#include "battleFactory.h"

std::shared_ptr<IBattle> BattleFactory::createBattle(std::vector<std::shared_ptr<Army>> &armies) {
    return std::make_shared<Battle>(Battle(armies, this->logger));
}

BattleFactory::BattleFactory() {
    this->logger = std::make_shared<Battle_logger>(Battle_logger());
}