//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_WARRIORFACTORY_H
#define GAME_WARRIORFACTORY_H

#include <memory>
#include "../includes/allUnits.h"

class WarriorFactory {
public:
    virtual std::shared_ptr<Archer> createArcher() = 0;
    virtual std::shared_ptr<Horseman> createHorseman() = 0;
    virtual std::shared_ptr<Infantryman> createInfantryman() = 0;
};

#endif //GAME_WARRIORFACTORY_H
