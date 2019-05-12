//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_ARMYFACTORYASSEMBLY_H
#define GAME_ARMYFACTORYASSEMBLY_H


#include <memory>
#include "factories/ISquadFactory.h"
#include "factories/ILeaderFactory.h"
#include "factories/armyFactory.h"

class ArmyFactoryAssembly {
private:
    std::shared_ptr<ILeaderFactory> leaderFactory;
    std::shared_ptr<IKingdomGenerator> kingdomGenerator;
    std::shared_ptr<ILeaderNameGenerator> leaderNameGenerator;
    std::shared_ptr<WarriorFactory> sarleonWarriorFactory;
    std::shared_ptr<WarriorFactory> ravensternWarriorFactory;
public:
    ArmyFactoryAssembly();

    std::shared_ptr<ArmyFactory> getArmyFactory();
};


#endif //GAME_ARMYFACTORYASSEMBLY_H
