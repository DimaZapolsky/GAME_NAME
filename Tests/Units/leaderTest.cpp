//
// Created by Dima Zapolsky on 12/05/2019.
//

#include <gtest/gtest.h>
#include "../../src/leader.h"
#include "../../src/includes/allUnits.h"

class LeaderTest : public ::testing::Test {
protected:
    std::shared_ptr<Leader> leader;

    virtual void TearDown() {}

    virtual void SetUp() {
        leader = std::shared_ptr<Leader>(new Leader("Leader", Sarleon, 3228, 11, 12, 13));
    }
};

TEST_F(LeaderTest, gettersTest) {
    EXPECT_EQ(leader->getName(), "Leader");
    EXPECT_EQ(leader->getKingdom(), Sarleon);
    EXPECT_EQ(leader->getHonor(), 3228);
    EXPECT_NO_THROW(leader->addHonor(3220));
    EXPECT_EQ(leader->getHonor(), 6448);
    EXPECT_EQ(leader->getStrategic(), 11);
    EXPECT_EQ(leader->getCharisma(), 12);
    EXPECT_EQ(leader->getCoaching(), 13);
}

TEST_F(LeaderTest, leadersArmyTest) {
    auto army = std::shared_ptr<Army>(new Army());
    std::shared_ptr<Squad> squad = std::shared_ptr<Squad>(new Squad());
    army->setArmy(squad);
    army->setLeader(leader);
    army->setMoney(12345);
    leader->setArmy(army);
    EXPECT_EQ(leader->getArmy()->getMoney(), 12345);
    EXPECT_EQ(leader->getMoney(), 12345);
    leader->decreaseMoney(12345);
    EXPECT_EQ(leader->getArmy()->getMoney(), 0);
    EXPECT_EQ(leader->getMoney(), 0);
    auto war1 = std::shared_ptr<SarleonInfantryman>(new SarleonInfantryman());
    auto war2 = std::shared_ptr<SarleonArcher>(new SarleonArcher());
    auto war3 = std::shared_ptr<SarleonHorseman>(new SarleonHorseman());
    leader->addWarrior(war1);
    leader->addWarrior(war2);
    leader->addWarrior(war3);
    EXPECT_EQ(leader->getArmy()->getFood(), war1->getFood() + war2->getFood() + war3->getFood());
    EXPECT_EQ(leader->getFood(), war1->getFood() + war2->getFood() + war3->getFood());
    EXPECT_EQ(leader->getArmy()->getCanCarry(), war1->getCanCarry() + war2->getCanCarry() + war3->getCanCarry());
    EXPECT_EQ(leader->getCanCarry(), war1->getCanCarry() + war2->getCanCarry() + war3->getCanCarry());
    EXPECT_EQ(leader->getArmy()->getCost(), war1->getCost() + war2->getCost() + war3->getCost());
    EXPECT_EQ(leader->getArmyCost(), war1->getCost() + war2->getCost() + war3->getCost());
    EXPECT_EQ(leader->getFoodCnt(), 0);
    EXPECT_EQ(leader->getArmy()->getFoodCnt(), 0);
    EXPECT_NO_THROW(leader->addFood(10));
    EXPECT_EQ(leader->getFoodCnt(), 10);
    EXPECT_EQ(leader->getArmy()->getFoodCnt(), 10);
    EXPECT_EQ(leader->getUnpayedWeeks(), 0);
    EXPECT_EQ(leader->getArmy()->getUnpayedWeeks(), 0);
    EXPECT_NO_THROW(leader->increaseUnpayedWeeks());
    EXPECT_EQ(leader->getUnpayedWeeks(), 1);
    EXPECT_EQ(leader->getArmy()->getUnpayedWeeks(), 1);
}