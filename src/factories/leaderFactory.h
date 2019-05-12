//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_LEADERFACTORY_H
#define GAME_LEADERFACTORY_H


#include "ILeaderFactory.h"

class LeaderFactory: public ILeaderFactory {
private:
    std::shared_ptr<ILeaderNameGenerator> nameGenerator;
    std::shared_ptr<IKingdomGenerator> kingdomGenerator;
public:
    std::shared_ptr<Leader> generateLeader() override ;
    void setNameGenerator(std::shared_ptr<ILeaderNameGenerator> nameGenerator) override ;
    void setKingdomGenerator(std::shared_ptr<IKingdomGenerator> kingdomGen) override ;
};


#endif //GAME_LEADERFACTORY_H
