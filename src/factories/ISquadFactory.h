//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_ISQUADFACTORY_H
#define GAME_ISQUADFACTORY_H

#include "../squad.h"
#include "warriorFactory.h"

class ISquadFactory {
public:
    virtual std::shared_ptr<Squad> generateSquad(int amount) = 0;
    virtual void setWarriorsFactory(std::shared_ptr<WarriorFactory> factory) = 0;
};

#endif //GAME_ISQUADFACTORY_H
