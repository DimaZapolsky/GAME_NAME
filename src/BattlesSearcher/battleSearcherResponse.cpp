//
// Created by Dima Zapolsky on 2019/05/12.
//

#include "battleSearcherResponse.h"

BattleSearcherResponse::BattleSearcherResponse(battleSearcherEnum eventType, std::shared_ptr<Army> army) {
    this->eventType = eventType;
    this->army = army;
}

battleSearcherEnum BattleSearcherResponse::getEventType() const {
    return this->eventType;
}

std::shared_ptr<Army> BattleSearcherResponse::getArmy() const {
    return army;
}

