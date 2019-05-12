//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_RAVENSTERNWARRIORFACTORY_H
#define GAME_RAVENSTERNWARRIORFACTORY_H

#include "warriorFactory.h"

class RavensternWarriorFactory : public WarriorFactory {
public:
    std::shared_ptr<Archer> createArcher() override;
    std::shared_ptr<Horseman> createHorseman() override;
    std::shared_ptr<Infantryman> createInfantryman() override;
};

#endif //GAME_RAVENSTERNWARRIORFACTORY_H
