//
// Created by Dima Zapolsky on 2019/05/12.
//

#include "armyFactoryAssembly.h"
#include "factories/leaderNameGenerator.h"
#include "factories/kingdomGenerator.h"
#include "factories/squadFactory.h"
#include "factories/leaderFactory.h"
#include "includes/allFactories.h"

ArmyFactoryAssembly::ArmyFactoryAssembly() {
    leaderNameGenerator = std::shared_ptr<ILeaderNameGenerator>(new LeaderNameGenerator());
    kingdomGenerator = std::shared_ptr<IKingdomGenerator>(new KingdomGenerator());
    leaderFactory = std::shared_ptr<ILeaderFactory>(new LeaderFactory());

    leaderFactory->setKingdomGenerator(kingdomGenerator);
    leaderFactory->setNameGenerator(leaderNameGenerator);

    ravensternWarriorFactory = std::shared_ptr<WarriorFactory>(new RavensternWarriorFactory());
    sarleonWarriorFactory = std::shared_ptr<WarriorFactory>(new SarleonWarriorFactory());
}

std::shared_ptr<ArmyFactory> ArmyFactoryAssembly::getArmyFactory() {
    auto armyFactory = std::shared_ptr<ArmyFactory>(new ArmyFactory());
    auto ravenFactory = std::shared_ptr<ISquadFactory>(new SquadFactory);
    ravenFactory->setWarriorsFactory(std::shared_ptr<WarriorFactory>(ravensternWarriorFactory));

    auto sarleonFactory = std::shared_ptr<ISquadFactory>(new SquadFactory);
    sarleonFactory->setWarriorsFactory(std::shared_ptr<WarriorFactory>(sarleonWarriorFactory));

    armyFactory->setLeaderFactory(leaderFactory);
    armyFactory->setRavensternSquadFactory(ravenFactory);
    armyFactory->setSarleonSquadFactory(sarleonFactory);
    return armyFactory;
}