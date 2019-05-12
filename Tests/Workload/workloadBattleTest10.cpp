//
// Created by Dima Zapolsky on 13/05/2019.
//

#include <gtest/gtest.h>
#include "../../src/armyFactoryAssembly.h"
#include "../../src/battleFactory.h"

class WorkloadBattleTest10: public ::testing::Test {
protected:

    std::shared_ptr<ArmyFactory> factory;
    std::shared_ptr<BattleFactory> battleFactory;


    virtual void TearDown() {}

    virtual void SetUp() {
        factory = ArmyFactoryAssembly().getArmyFactory();
        battleFactory = std::shared_ptr<BattleFactory>(new BattleFactory());
    }
};

TEST_F(WorkloadBattleTest10, WorkloadBattleTest10_1) {
    int t = clock();
    auto armiesList = factory->generateArmies(10);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
    EXPECT_TRUE((clock() - t) * 25 < CLK_TCK * 10000);
}

TEST_F(WorkloadBattleTest10, WorkloadBattleTest10_2) {
    int t = clock();
    auto armiesList = factory->generateArmies(10);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
    EXPECT_TRUE((clock() - t) * 25 < CLK_TCK * 10000);
}

TEST_F(WorkloadBattleTest10, WorkloadBattleTest10_3) {
    int t = clock();
    auto armiesList = factory->generateArmies(10);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
    EXPECT_TRUE((clock() - t) * 25 < CLK_TCK * 10000);
}

TEST_F(WorkloadBattleTest10, WorkloadBattleTest10_4) {
    int t = clock();
    auto armiesList = factory->generateArmies(10);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
    EXPECT_TRUE((clock() - t) * 25 < CLK_TCK * 10000);
}

TEST_F(WorkloadBattleTest10, WorkloadBattleTest10_5) {
    int t = clock();
    auto armiesList = factory->generateArmies(10);
    auto battle = battleFactory->createBattle(armiesList);
    EXPECT_NO_THROW(battle->start_war_test());
    EXPECT_TRUE((clock() - t) * 25 < CLK_TCK * 10000);
}