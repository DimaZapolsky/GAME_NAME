//
// Created by Dima Zapolsky on 13/05/2019.
//

#include <gtest/gtest.h>
#include "../../src/armyFactoryAssembly.h"
#include "../../src/battleFactory.h"

class WorkloadBattleTest100: public ::testing::Test {
protected:

    std::shared_ptr<ArmyFactory> factory;
    std::shared_ptr<BattleFactory> battleFactory;


    virtual void TearDown() {}

    virtual void SetUp() {
        factory = ArmyFactoryAssembly().getArmyFactory();
        battleFactory = std::shared_ptr<BattleFactory>(new BattleFactory());
    }
};

TEST_F(WorkloadBattleTest100, WorkloadBattleTest100_1) {
    int t = clock();
    auto armiesList = factory->generateArmies(100);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
    EXPECT_TRUE((clock() - t) < CLK_TCK * 10000);
}

TEST_F(WorkloadBattleTest100, WorkloadBattleTest100_2) {
    int t = clock();
    auto armiesList = factory->generateArmies(100);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
    EXPECT_TRUE((clock() - t)  < CLK_TCK * 10000);
}

TEST_F(WorkloadBattleTest100, WorkloadBattleTest100_3) {
    int t = clock();
    auto armiesList = factory->generateArmies(100);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
    EXPECT_TRUE((clock() - t) < CLK_TCK * 10000);
}

TEST_F(WorkloadBattleTest100, WorkloadBattleTest100_4) {
    int t = clock();
    auto armiesList = factory->generateArmies(100);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
    EXPECT_TRUE((clock() - t) < CLK_TCK * 10000);
}

TEST_F(WorkloadBattleTest100, WorkloadBattleTest100_5) {
    int t = clock();
    auto armiesList = factory->generateArmies(100);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
    EXPECT_TRUE((clock() - t) < CLK_TCK * 10000);
}