//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_SARLEONWARRIORFACTORY_H
#define GAME_SARLEONWARRIORFACTORY_H

#include "warriorFactory.h"

class SarleonWarriorFactory : public WarriorFactory {
public:
    std::shared_ptr<Archer> createArcher() override;
    std::shared_ptr<Horseman> createHorseman() override;
    std::shared_ptr<Infantryman> createInfantryman() override;
};

#endif //GAME_SARLEONWARRIORFACTORY_H
