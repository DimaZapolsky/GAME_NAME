//
// Created by Dima Zapolsky 2019/05/12.
//

#include <gtest/gtest.h>
#include "../../src/factories/warriorFactory.h"
#include "../../src/factories/ILeaderFactory.h"
#include "../../src/factories/leaderFactory.h"
#include "../../src/includes/allFactories.h"
#include "../../src/factories/IArmyFactory.h"
#include "../../src/factories/armyFactory.h"
#include "../../src/factories/squadFactory.h"
#include "../../src/factories/kingdomGenerator.h"
#include "../../src/factories/leaderNameGenerator.h"

class ArmyFactoryTest: public ::testing::Test {
protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {

    }

    std::shared_ptr<WarriorFactory> sarleonFactory;
    std::shared_ptr<WarriorFactory> ravenFactory;
    std::shared_ptr<ILeaderFactory> leaderFactory;
    std::shared_ptr<IArmyFactory> armyFactory;

    std::shared_ptr<ISquadFactory> sarleonSquadFactory;
    std::shared_ptr<ISquadFactory> ravenSquadFactory;
public:
    ArmyFactoryTest() : Test() {
        leaderFactory = std::shared_ptr<ILeaderFactory>(new LeaderFactory());
        leaderFactory->setKingdomGenerator(std::shared_ptr<IKingdomGenerator>(new KingdomGenerator()));
        leaderFactory->setNameGenerator(std::shared_ptr<ILeaderNameGenerator>(new LeaderNameGenerator()));
        sarleonFactory = std::shared_ptr<WarriorFactory>(new SarleonWarriorFactory());

        ravenFactory = std::shared_ptr<WarriorFactory>(new RavensternWarriorFactory());


        sarleonSquadFactory = std::shared_ptr<ISquadFactory>(new SquadFactory());
        sarleonSquadFactory->setWarriorsFactory(sarleonFactory);

        ravenSquadFactory = std::shared_ptr<ISquadFactory>(new SquadFactory());
        ravenSquadFactory->setWarriorsFactory(ravenFactory);

        armyFactory = std::shared_ptr<IArmyFactory>(new ArmyFactory());
    }

    void configure() {
        armyFactory->setSarleonSquadFactory(sarleonSquadFactory);
        armyFactory->setRavensternSquadFactory(ravenSquadFactory);
        armyFactory->setLeaderFactory(leaderFactory);

    }
};

TEST_F(ArmyFactoryTest, Throw) {
    EXPECT_THROW(armyFactory->generateArmies(10), std::exception);
}

TEST_F(ArmyFactoryTest, NoThrow) {
    configure();
    EXPECT_NO_THROW();
}

TEST_F(ArmyFactoryTest, CheckGenValues) {
    configure();
    std::vector<std::shared_ptr<Army>> army = armyFactory->generateArmies(10);
    EXPECT_EQ(army.size(), 10);

    for (auto const &el : army) {
        EXPECT_NE(el->getArmy()->getAllWarriors().size(), 0);
        EXPECT_NE(el->getLeader(), nullptr);
        EXPECT_EQ(el->getLeader()->getArmy(), el);
    }
}