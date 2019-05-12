//
// Created by Dima Zapolsky on 13/05/2019.
//

#include <gtest/gtest.h>
#include "../../src/armyFactoryAssembly.h"
#include "../../src/battleFactory.h"

class StressTest1k: public ::testing::Test {
protected:

    std::shared_ptr<ArmyFactory> factory;
    std::shared_ptr<BattleFactory> battleFactory;


    virtual void TearDown() {}

    virtual void SetUp() {
        factory = ArmyFactoryAssembly().getArmyFactory();
        battleFactory = std::shared_ptr<BattleFactory>(new BattleFactory());
    }
};

TEST_F(StressTest1k, StressTest1k1) {
    auto armiesList = factory->generateArmies(1000);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
}

TEST_F(StressTest1k, StressTest1k2) {
    auto armiesList = factory->generateArmies(1000);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
}

TEST_F(StressTest1k, StressTest1k3) {
    auto armiesList = factory->generateArmies(1000);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
}

TEST_F(StressTest1k, StressTest1k4) {
    auto armiesList = factory->generateArmies(1000);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
}

TEST_F(StressTest1k, StressTest1k5) {
    auto armiesList = factory->generateArmies(1000);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
}
