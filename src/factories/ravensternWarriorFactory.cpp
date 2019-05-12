//
// Created by Dima Zapolsky on 09/05/2019.
//

#include "ravensternWarriorFactory.h"
#include "../includes/allUnits.h"

std::shared_ptr<Archer> RavensternWarriorFactory::createArcher() {
    return std::shared_ptr<RavensternArcher>(new RavensternArcher());
}

std::shared_ptr<Horseman> RavensternWarriorFactory::createHorseman() {
    return std::shared_ptr<RavensternHorseman>(new RavensternHorseman());
}

std::shared_ptr<Infantryman> RavensternWarriorFactory::createInfantryman() {
    return std::shared_ptr<RavensternInfantryman>(new RavensternInfantryman());
}