//
// Created by Dima Zapolsky 2019/05/12.
//

#include <gtest/gtest.h>
#include "../../src/factories/ILeaderFactory.h"
#include "../../src/factories/leaderFactory.h"
#include "../../src/factories/leaderNameGenerator.h"
#include "../../src/factories/kingdomGenerator.h"

class LeaderFactoryTest: public ::testing::Test {
protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {

    }
    std::shared_ptr<ILeaderFactory> factory;

public:
    LeaderFactoryTest() : Test() {
        factory = std::shared_ptr<ILeaderFactory>(new LeaderFactory());
    }

    void configure() {
        factory->setNameGenerator(std::shared_ptr<ILeaderNameGenerator>(new LeaderNameGenerator()));
        factory->setKingdomGenerator(std::shared_ptr<IKingdomGenerator>(new KingdomGenerator()));
    }
};

TEST_F(LeaderFactoryTest, NullValues) {
    EXPECT_THROW(factory->generateLeader(), std::exception);
}

TEST_F(LeaderFactoryTest, NoThrow) {
    configure();

    EXPECT_NO_THROW(factory->generateLeader());
    auto val = factory->generateLeader();
    EXPECT_NE(val, nullptr);
    EXPECT_NE(val->getName(), "");
    EXPECT_EQ(val->getArmy(), nullptr);
}

