//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_IARMYFACTORY_H
#define GAME_IARMYFACTORY_H

#include "../army.h"
#include "ILeaderFactory.h"
#include "ISquadFactory.h"
#include "warriorFactory.h"

class IArmyFactory {
public:
    virtual std::vector<std::shared_ptr<Army>> generateArmies(int amount) = 0;
    virtual void setLeaderFactory(std::shared_ptr<ILeaderFactory> leaderGenerator) = 0;
    virtual void setSarleonSquadFactory(std::shared_ptr<ISquadFactory> squadGenerator) = 0;
    virtual void setRavensternSquadFactory(std::shared_ptr<ISquadFactory> squadGenerator) = 0;
};

#endif //GAME_IARMYFACTORY_H
