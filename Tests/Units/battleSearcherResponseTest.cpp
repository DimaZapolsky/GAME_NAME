//
// Created by Dima Zapolsky 2019/05/12.
//

#include <gtest/gtest.h>
#include "../../src/BattlesSearcher/battleSearcherResponse.h"

class BattleSearcherResponseTest: public ::testing::Test {
protected:
    virtual void SetUp() {}
    virtual void TearDown() {}

    BattleSearcherResponse* response;
public:
    BattleSearcherResponseTest() : Test() {
    }
};

TEST_F(BattleSearcherResponseTest, TestGetters) {
    response = new BattleSearcherResponse(NothingHappened, nullptr);
    EXPECT_EQ(response->getEventType(), NothingHappened);
    EXPECT_EQ(response->getArmy(), nullptr);
    auto army = std::shared_ptr<Army>(new Army());
    response = new BattleSearcherResponse(FoundArmyToAttack, army);
    EXPECT_EQ(response->getEventType(), FoundArmyToAttack);
    EXPECT_EQ(response->getArmy(), army);
}