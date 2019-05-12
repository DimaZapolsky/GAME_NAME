//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_SQUADFACTORY_H
#define GAME_SQUADFACTORY_H


#include "ISquadFactory.h"

class SquadFactory: public ISquadFactory {
private:
    std::shared_ptr<WarriorFactory> warriorFactory;
public:
    std::shared_ptr<Squad> generateSquad(int amount) override ;
    void setWarriorsFactory(std::shared_ptr<WarriorFactory> factory) override ;
};


#endif //GAME_SQUADFACTORY_H
