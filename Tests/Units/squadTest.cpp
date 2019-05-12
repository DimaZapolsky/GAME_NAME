//
// Created by Dima Zapolsky on 12/05/2019.
//

#include <gtest/gtest.h>
#include "../../src/squad.h"
#include "../../src/includes/allUnits.h"

class SquadTest : public ::testing::Test {
protected:
    std::shared_ptr<Squad> squad;

    virtual void TearDown() {}

    virtual void SetUp() {
        squad = std::shared_ptr<Squad>(new Squad());
    }
};

TEST_F(SquadTest, addSquadTest) {
    for (int i = 0; i <= 10; ++i) {
        auto squadi = std::shared_ptr<Squad>(new Squad());
        EXPECT_EQ(squad->getChildrenSize(), i);
        EXPECT_NO_THROW(squad->add(squadi));
        EXPECT_EQ(squad->getChildrenSize(), i + 1);
    }
}

TEST_F(SquadTest, addWarriorTest) {
    for (int i = 0; i <= 10; ++i) {
        auto squadi = std::shared_ptr<SarleonInfantryman>(new SarleonInfantryman());
        EXPECT_EQ(squad->getChildrenSize(), i);
        EXPECT_NO_THROW(squad->add(squadi));
        EXPECT_EQ(squad->getChildrenSize(), i + 1);
    }
}

TEST_F(SquadTest, agrFunctiondTest) {
    auto war1 = std::shared_ptr<SarleonInfantryman>(new SarleonInfantryman());
    auto war2 = std::shared_ptr<SarleonArcher>(new SarleonArcher());
    auto war3 = std::shared_ptr<SarleonHorseman>(new SarleonHorseman());
    EXPECT_NO_THROW(squad->add(war1));
    EXPECT_NO_THROW(squad->add(war2));
    EXPECT_NO_THROW(squad->add(war3));

    EXPECT_EQ(squad->getCost(), war1->getCost() + war2->getCost() + war3->getCost());
    EXPECT_EQ(squad->getCanCarry(), war1->getCanCarry() + war2->getCanCarry() + war3->getCanCarry());
    EXPECT_EQ(squad->getFood(), war1->getFood() + war2->getFood() + war3->getFood());
}

TEST_F(SquadTest, addTacticTest) {
    auto tactic = std::shared_ptr<Tactic>(new Tactic(Tactic::all, Tactic::Attack, Tactic::Rear, Tactic::all));
    auto squad1 = std::shared_ptr<Squad>(new Squad());
    auto squad2 = std::shared_ptr<Squad>(new Squad());
    auto squad3 = std::shared_ptr<Squad>(new Squad());
    EXPECT_NO_THROW(squad->add(squad1));
    EXPECT_NO_THROW(squad->add(squad2));
    EXPECT_NO_THROW(squad->add(squad3));
    EXPECT_NO_THROW(squad->setTactic(tactic));
    EXPECT_TRUE(squad1->getTactic() != nullptr);
    EXPECT_TRUE(squad2->getTactic() != nullptr);
    EXPECT_TRUE(squad3->getTactic() != nullptr);
}