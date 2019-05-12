//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_ARMYFACTORY_H
#define GAME_ARMYFACTORY_H


#include "IArmyFactory.h"

class ArmyFactory: public IArmyFactory {
private:
    std::shared_ptr<ISquadFactory> sarleonSquadFactory;
    std::shared_ptr<ISquadFactory> ravensternSquadFactory;

    std::shared_ptr<ILeaderFactory> leaderFactory;

    std::shared_ptr<Army> generateArmy();
public:
    void setLeaderFactory(std::shared_ptr<ILeaderFactory> leaderGenerator) override ;
    void setSarleonSquadFactory(std::shared_ptr<ISquadFactory> squadGenerator) override ;
    void setRavensternSquadFactory(std::shared_ptr<ISquadFactory> squadGenerator) override ;
    std::vector<std::shared_ptr<Army>> generateArmies(int amount) override ;
};


#endif //GAME_ARMYFACTORY_H
