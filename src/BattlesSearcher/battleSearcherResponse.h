//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_BATTLESEARCHERRESPONSE_H
#define GAME_BATTLESEARCHERRESPONSE_H


#include "battleSearcherEnum.h"
#include "../army.h"

class BattleSearcherResponse {
private:
    battleSearcherEnum eventType;
    std::shared_ptr<Army> army;
public:
    BattleSearcherResponse(battleSearcherEnum eventType, std::shared_ptr<Army> army);
    battleSearcherEnum getEventType() const;
    std::shared_ptr<Army> getArmy() const;
};


#endif //GAME_BATTLESEARCHERRESPONSE_H
