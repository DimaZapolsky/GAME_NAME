//
// Created by Dima Zapolsky 2019/05/12.
//
#include "gtest/gtest.h"
#include "../../src/Logger/battleLog.h"
#include "../../src/includes/allFactories.h"
#include "../../src/Logger/battle_logger.h"

class LogTest: public ::testing::Test {
protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {

    }

    std::shared_ptr<SarleonWarriorFactory> sarleonFactory;
    std::shared_ptr<RavensternWarriorFactory> ravenFactory;
    std::shared_ptr<IBattle_logger> logger;

    std::shared_ptr<Warrior> victim;
    std::shared_ptr<Warrior> predator;
public:
    LogTest() : Test() {
        ravenFactory = std::shared_ptr<RavensternWarriorFactory>(new RavensternWarriorFactory());
        sarleonFactory = std::shared_ptr<SarleonWarriorFactory>(new SarleonWarriorFactory());
        logger = std::shared_ptr<IBattle_logger>(new Battle_logger());
        victim = sarleonFactory->createArcher();
        predator = ravenFactory->createArcher();
    }
};

TEST_F(LogTest, BattleLogGetters) {
    auto log = new Battle_log(victim, predator, 1);
    EXPECT_EQ(log->get_tick(), 1);
    EXPECT_EQ(log->get_victim(), victim->getName());
    EXPECT_EQ(log->get_predator(), predator->getName());
}