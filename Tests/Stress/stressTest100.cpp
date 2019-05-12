//
// Created by Dima Zapolsky on 13/05/2019.
//

#include <gtest/gtest.h>
#include "../../src/armyFactoryAssembly.h"
#include "../../src/battleFactory.h"

class StressTest100: public ::testing::Test {
protected:

    std::shared_ptr<ArmyFactory> factory;
    std::shared_ptr<BattleFactory> battleFactory;


    virtual void TearDown() {}

    virtual void SetUp() {
        factory = ArmyFactoryAssembly().getArmyFactory();
        battleFactory = std::shared_ptr<BattleFactory>(new BattleFactory());
    }
};

TEST_F(StressTest100, StressTest100_1) {
    auto armiesList = factory->generateArmies(100);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
}

TEST_F(StressTest100, StressTest100_2) {
    auto armiesList = factory->generateArmies(100);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
}

TEST_F(StressTest100, StressTest100_3) {
    auto armiesList = factory->generateArmies(100);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
}

TEST_F(StressTest100, StressTest100_4) {
    auto armiesList = factory->generateArmies(100);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
}

TEST_F(StressTest100, StressTest100_5) {
    auto armiesList = factory->generateArmies(100);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
}
