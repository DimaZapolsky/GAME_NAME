//
// Created by Dima Zapolsky on 13/05/2019.
//

#include <gtest/gtest.h>
#include "../../src/squad.h"
#include "../../src/includes/allUnits.h"

class StressTestAdd1kk: public ::testing::Test {
protected:

    std::shared_ptr<Squad> squad;
    int add;

    virtual void TearDown() {}

    virtual void SetUp() {
        add = 1e6;
        squad = std::shared_ptr<Squad>(new Squad());
    }
};

TEST_F(StressTestAdd1kk, StressTestAdd1kk_1) {
    for (int i = 0; i < add; ++i) {
        squad->add(std::shared_ptr<SarleonArcher>(new SarleonArcher()));
    }
}

TEST_F(StressTestAdd1kk, StressTestAdd1kk_2) {
    for (int i = 0; i < add; ++i) {
        squad->add(std::shared_ptr<SarleonHorseman>(new SarleonHorseman()));
    }
}

TEST_F(StressTestAdd1kk, StressTestAdd1kk_3) {
    for (int i = 0; i < add; ++i) {
        squad->add(std::shared_ptr<SarleonInfantryman>(new SarleonInfantryman()));
    }
}

TEST_F(StressTestAdd1kk, StressTestAdd1kk_4) {
    for (int i = 0; i < add; ++i) {
        squad->add(std::shared_ptr<RavensternInfantryman>(new RavensternInfantryman()));
    }
}

TEST_F(StressTestAdd1kk, StressTestAdd1kk_5) {
    for (int i = 0; i < add; ++i) {
        squad->add(std::shared_ptr<RavensternHorseman>(new RavensternHorseman()));
    }
}

TEST_F(StressTestAdd1kk, StressTestAdd1kk_6) {
    for (int i = 0; i < add; ++i) {
        squad->add(std::shared_ptr<RavensternArcher>(new RavensternArcher()));
    }
}
