//
// Created by Dima Zapolsky on 09/05/2019.
//

#include "sarleonWarriorFactory.h"
#include "../includes/allUnits.h"

std::shared_ptr<Archer> SarleonWarriorFactory::createArcher() {
    return std::shared_ptr<SarleonArcher>(new SarleonArcher());
}

std::shared_ptr<Horseman> SarleonWarriorFactory::createHorseman() {
    return std::shared_ptr<SarleonHorseman>(new SarleonHorseman());
}

std::shared_ptr<Infantryman> SarleonWarriorFactory::createInfantryman() {
    return std::shared_ptr<SarleonInfantryman>(new SarleonInfantryman());
}