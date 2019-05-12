//
// Created by Dima Zapolsky 2019/05/12.
//

#include <gtest/gtest.h>
#include "../../src/BattlesSearcher/IBattleSearcher.h"
#include "../../src/BattlesSearcher/battleSearcher.h"
#include "../../src/factories/ILeaderFactory.h"
#include "../../src/factories/leaderFactory.h"
#include "../../src/factories/leaderNameGenerator.h"
#include "../../src/factories/kingdomGenerator.h"
#include "../../src/factories/IArmyFactory.h"
#include "../../src/factories/armyFactory.h"
#include "../../src/factories/squadFactory.h"
#include "../../src/includes/allFactories.h"

class BattleSearcherTest: public ::testing::Test {
protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
public:
    std::shared_ptr<IBattleSearcher> battleSearcher;
    std::shared_ptr<ILeaderFactory> leaderFactory;
    std::shared_ptr<IArmyFactory> armiesFactory;
    BattleSearcherTest() : Test() {
        battleSearcher = std::shared_ptr<IBattleSearcher>(new BattleSearcher());
        leaderFactory = std::shared_ptr<ILeaderFactory>(new LeaderFactory());
        leaderFactory->setNameGenerator(std::shared_ptr<ILeaderNameGenerator>(new LeaderNameGenerator()));
        leaderFactory->setKingdomGenerator(std::shared_ptr<IKingdomGenerator>(new KingdomGenerator()));
        armiesFactory = std::shared_ptr<IArmyFactory>(new ArmyFactory());
        armiesFactory->setLeaderFactory(leaderFactory);

        auto sarlSquadFactory = std::shared_ptr<ISquadFactory>(new SquadFactory());
        sarlSquadFactory->setWarriorsFactory(std::shared_ptr<WarriorFactory>(new SarleonWarriorFactory()));

        auto ravenSquadFactory = std::shared_ptr<ISquadFactory>(new SquadFactory());
        ravenSquadFactory->setWarriorsFactory(std::shared_ptr<WarriorFactory>(new RavensternWarriorFactory()));

        armiesFactory->setRavensternSquadFactory(ravenSquadFactory);
        armiesFactory->setSarleonSquadFactory(sarlSquadFactory);

        battleSearcher->setPlayer(leaderFactory->generateLeader());
    }

    static bool afterSettinEnemyArmy(battleSearcherEnum const battleSearcherEnum) {
        return battleSearcherEnum == NothingHappened || battleSearcherEnum == ArmyJoinedApponentSide ||
        battleSearcherEnum == ArmyJoinedYourSide;
    }

};

TEST_F(BattleSearcherTest, CheckSetter) {
    auto generatedArmy = armiesFactory->generateArmies(1)[0];
    EXPECT_EQ(battleSearcher->getCurrentEnemy(), nullptr);
    battleSearcher->setCurrentEnemy(generatedArmy);
    EXPECT_EQ(battleSearcher->getCurrentEnemy(), generatedArmy);
}

TEST_F(BattleSearcherTest, CheckResponses) {
    auto generatedArmies = armiesFactory->generateArmies(10);
    battleSearcher->setWanderingArmies(generatedArmies);
    for (int i = 0; i < 10; ++i) {
        auto response = battleSearcher->requestNewEvent();

        if (response.getEventType() == NothingHappened) {
            EXPECT_EQ(response.getArmy(), nullptr);
        } else if (response.getEventType() == FoundArmyToAttack) {
            EXPECT_NE(response.getArmy(), nullptr);
        } else if (response.getEventType() == IncomingAttack) {
            EXPECT_NE(response.getArmy(), nullptr);
        }
    }
    auto generatedArmy = armiesFactory->generateArmies(1)[0];

    battleSearcher->setCurrentEnemy(generatedArmy);
    for (int i = 0; i < 10; ++i) {
        auto response = battleSearcher->requestNewEvent();
        EXPECT_PRED1(afterSettinEnemyArmy, response.getEventType());
    }
}

TEST_F(BattleSearcherTest, ObserverCompletion) {
    auto generatedArmy = armiesFactory->generateArmies(1)[0];
    battleSearcher->setCurrentEnemy(generatedArmy);
    battleSearcher->battleHasEnded();
    EXPECT_EQ(battleSearcher->getCurrentEnemy(), nullptr);
}