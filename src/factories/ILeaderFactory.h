//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_ILEADERFACTORY_H
#define GAME_ILEADERFACTORY_H

#include "../leader.h"
#include "ILeaderNameGenerator.h"
#include "IKingdomGenerator.h"

class ILeaderFactory {
public:
    virtual std::shared_ptr<Leader> generateLeader() = 0;
    virtual void setNameGenerator(std::shared_ptr<ILeaderNameGenerator> nameGenerator) = 0;
    virtual void setKingdomGenerator(std::shared_ptr<IKingdomGenerator> kingdomGen) = 0;
};

#endif //GAME_ILEADERFACTORY_H
