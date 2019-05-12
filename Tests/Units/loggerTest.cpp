//
// Created by Dima Zapolsky 2019/05/12.
//

#include "gtest/gtest.h"
#include "../../src/Logger/battle_logger.h"
#include "../../src/includes/allUnits.h"
#include "../../src/includes/allFactories.h"

class LoggerTest: public ::testing::Test {
protected:
    std::shared_ptr<SarleonWarriorFactory> sarleonFactory;
    std::shared_ptr<RavensternWarriorFactory> ravenFactory;
    std::shared_ptr<IBattle_logger> logger;

    std::shared_ptr<Warrior> victim;
    std::shared_ptr<Warrior> predator;
    int tick = 1;

    virtual void TearDown() {

    }

    virtual void SetUp() {

    }
public:
    LoggerTest() : Test() {
        ravenFactory = std::shared_ptr<RavensternWarriorFactory>(new RavensternWarriorFactory());
        sarleonFactory = std::shared_ptr<SarleonWarriorFactory>(new SarleonWarriorFactory());
        logger = std::shared_ptr<IBattle_logger>(new Battle_logger());
        victim = sarleonFactory->createArcher();
        predator = ravenFactory->createArcher();
    }
};



TEST_F(LoggerTest, putLogSuccessfully) {
    auto testLog = std::shared_ptr<IBattle_log>(new Battle_log(victim, predator, tick));
    logger->addLog(testLog);
    EXPECT_EQ(testLog, logger->getLogs()[0]);
}


TEST_F(LoggerTest, clearLogSuccessfully) {
    int tick = 1;
    auto testLog = std::shared_ptr<IBattle_log>(new Battle_log(victim, predator, tick));
    logger->addLog(testLog);
    logger->battleHasEnded();
    EXPECT_EQ(logger->getLogs().size(), 0);
}

TEST_F(LoggerTest, stringLog) {
    int tick = 1;
    auto testLog = std::shared_ptr<IBattle_log>(new Battle_log(victim, predator, tick));
    logger->addLog(testLog);
    EXPECT_EQ(logger->getStringLogs(), "Сарлеонский лучник (0, 0) has been slain by Равенстернский лучник (0, 0)\n");
}