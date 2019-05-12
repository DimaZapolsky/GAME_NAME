//
// Created by Dima Zapolsky on 12/05/2019.
//

#include "gtest/gtest.h"
#include "../../src/tactic.h"
#include "../../src/includes/allUnits.h"

class tacticTest : public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {}
};

TEST_F(tacticTest, canAttackCheck) {
    auto tactic = std::shared_ptr<Tactic>(new Tactic(Tactic::all, Tactic::Attack, Tactic::Rear, Tactic::all));
    auto SA = std::shared_ptr<SarleonArcher>(new SarleonArcher());
    auto SH = std::shared_ptr<SarleonHorseman>(new SarleonHorseman());
    auto SI = std::shared_ptr<SarleonInfantryman>(new SarleonInfantryman());
    auto RA = std::shared_ptr<RavensternArcher>(new RavensternArcher());
    auto RH = std::shared_ptr<RavensternHorseman>(new RavensternHorseman());
    auto RI = std::shared_ptr<RavensternInfantryman>(new RavensternInfantryman());

    EXPECT_TRUE(tactic->canAttack(SA));
    EXPECT_TRUE(tactic->canAttack(SH));
    EXPECT_TRUE(tactic->canAttack(SI));
    EXPECT_TRUE(tactic->canAttack(RA));
    EXPECT_TRUE(tactic->canAttack(RH));
    EXPECT_TRUE(tactic->canAttack(RI));

    EXPECT_TRUE(tactic->includes(SA));
    EXPECT_TRUE(tactic->includes(SH));
    EXPECT_TRUE(tactic->includes(SI));
    EXPECT_TRUE(tactic->includes(RA));
    EXPECT_TRUE(tactic->includes(RH));
    EXPECT_TRUE(tactic->includes(RI));

    tactic = std::shared_ptr<Tactic>(new Tactic(Tactic::all, Tactic::Defense, Tactic::Rear, Tactic::all));

    EXPECT_FALSE(tactic->canAttack(SA));
    EXPECT_FALSE(tactic->canAttack(SH));
    EXPECT_FALSE(tactic->canAttack(SI));
    EXPECT_FALSE(tactic->canAttack(RA));
    EXPECT_FALSE(tactic->canAttack(RH));
    EXPECT_FALSE(tactic->canAttack(RI));

    EXPECT_TRUE(tactic->includes(SA));
    EXPECT_TRUE(tactic->includes(SH));
    EXPECT_TRUE(tactic->includes(SI));
    EXPECT_TRUE(tactic->includes(RA));
    EXPECT_TRUE(tactic->includes(RH));
    EXPECT_TRUE(tactic->includes(RI));

    tactic = std::shared_ptr<Tactic>(new Tactic(Tactic::all, Tactic::Attack, Tactic::Rear, Tactic::Archer));

    EXPECT_TRUE(tactic->canAttack(SA));
    EXPECT_FALSE(tactic->canAttack(SH));
    EXPECT_FALSE(tactic->canAttack(SI));
    EXPECT_TRUE(tactic->canAttack(RA));
    EXPECT_FALSE(tactic->canAttack(RH));
    EXPECT_FALSE(tactic->canAttack(RI));

    EXPECT_TRUE(tactic->includes(SA));
    EXPECT_TRUE(tactic->includes(SH));
    EXPECT_TRUE(tactic->includes(SI));
    EXPECT_TRUE(tactic->includes(RA));
    EXPECT_TRUE(tactic->includes(RH));
    EXPECT_TRUE(tactic->includes(RI));

    tactic = std::shared_ptr<Tactic>(new Tactic(Tactic::all, Tactic::Attack, Tactic::Rear, Tactic::Horseman));

    EXPECT_FALSE(tactic->canAttack(SA));
    EXPECT_TRUE(tactic->canAttack(SH));
    EXPECT_FALSE(tactic->canAttack(SI));
    EXPECT_FALSE(tactic->canAttack(RA));
    EXPECT_TRUE(tactic->canAttack(RH));
    EXPECT_FALSE(tactic->canAttack(RI));

    EXPECT_TRUE(tactic->includes(SA));
    EXPECT_TRUE(tactic->includes(SH));
    EXPECT_TRUE(tactic->includes(SI));
    EXPECT_TRUE(tactic->includes(RA));
    EXPECT_TRUE(tactic->includes(RH));
    EXPECT_TRUE(tactic->includes(RI));

    tactic = std::shared_ptr<Tactic>(new Tactic(Tactic::all, Tactic::Attack, Tactic::Rear, Tactic::Infantryman));

    EXPECT_FALSE(tactic->canAttack(SA));
    EXPECT_FALSE(tactic->canAttack(SH));
    EXPECT_TRUE(tactic->canAttack(SI));
    EXPECT_FALSE(tactic->canAttack(RA));
    EXPECT_FALSE(tactic->canAttack(RH));
    EXPECT_TRUE(tactic->canAttack(RI));

    EXPECT_TRUE(tactic->includes(SA));
    EXPECT_TRUE(tactic->includes(SH));
    EXPECT_TRUE(tactic->includes(SI));
    EXPECT_TRUE(tactic->includes(RA));
    EXPECT_TRUE(tactic->includes(RH));
    EXPECT_TRUE(tactic->includes(RI));

    tactic = std::shared_ptr<Tactic>(new Tactic(Tactic::Archer, Tactic::Attack, Tactic::Rear, Tactic::all));

    EXPECT_TRUE(tactic->canAttack(SA));
    EXPECT_TRUE(tactic->canAttack(SH));
    EXPECT_TRUE(tactic->canAttack(SI));
    EXPECT_TRUE(tactic->canAttack(RA));
    EXPECT_TRUE(tactic->canAttack(RH));
    EXPECT_TRUE(tactic->canAttack(RI));

    EXPECT_TRUE(tactic->includes(SA));
    EXPECT_FALSE(tactic->includes(SH));
    EXPECT_FALSE(tactic->includes(SI));
    EXPECT_TRUE(tactic->includes(RA));
    EXPECT_FALSE(tactic->includes(RH));
    EXPECT_FALSE(tactic->includes(RI));

    tactic = std::shared_ptr<Tactic>(new Tactic(Tactic::Horseman, Tactic::Attack, Tactic::Rear, Tactic::all));

    EXPECT_TRUE(tactic->canAttack(SA));
    EXPECT_TRUE(tactic->canAttack(SH));
    EXPECT_TRUE(tactic->canAttack(SI));
    EXPECT_TRUE(tactic->canAttack(RA));
    EXPECT_TRUE(tactic->canAttack(RH));
    EXPECT_TRUE(tactic->canAttack(RI));

    EXPECT_FALSE(tactic->includes(SA));
    EXPECT_TRUE(tactic->includes(SH));
    EXPECT_FALSE(tactic->includes(SI));
    EXPECT_FALSE(tactic->includes(RA));
    EXPECT_TRUE(tactic->includes(RH));
    EXPECT_FALSE(tactic->includes(RI));

    tactic = std::shared_ptr<Tactic>(new Tactic(Tactic::Infantryman, Tactic::Attack, Tactic::Rear, Tactic::all));

    EXPECT_TRUE(tactic->canAttack(SA));
    EXPECT_TRUE(tactic->canAttack(SH));
    EXPECT_TRUE(tactic->canAttack(SI));
    EXPECT_TRUE(tactic->canAttack(RA));
    EXPECT_TRUE(tactic->canAttack(RH));
    EXPECT_TRUE(tactic->canAttack(RI));

    EXPECT_FALSE(tactic->includes(SA));
    EXPECT_FALSE(tactic->includes(SH));
    EXPECT_TRUE(tactic->includes(SI));
    EXPECT_FALSE(tactic->includes(RA));
    EXPECT_FALSE(tactic->includes(RH));
    EXPECT_TRUE(tactic->includes(RI));
}

