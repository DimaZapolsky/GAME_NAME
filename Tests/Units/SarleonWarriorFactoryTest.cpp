//
// Created by Dima Zapolsky 2019/05/12.
//

#include <gtest/gtest.h>
#include "../../src/includes/allFactories.h"
#include "../../src/functions.h"

class SarleonWarriorFactoryTest: public ::testing::Test {
protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {

    }

    std::shared_ptr<SarleonWarriorFactory> factory;

public:
    SarleonWarriorFactoryTest() : Test() {
        factory = std::shared_ptr<SarleonWarriorFactory>(new SarleonWarriorFactory());
    }

    static bool checkSarleonArcher(std::shared_ptr<Warrior> const &warrior) {
        return instanceof<SarleonArcher>(warrior.get());
    }

    static bool checkSarleonInfantry(std::shared_ptr<Warrior> const &warrior) {
        return instanceof<SarleonInfantryman>(warrior.get());
    }

    static bool checkSarleonHorseman(std::shared_ptr<Warrior> const &warrior) {
        return instanceof<SarleonHorseman>(warrior.get());
    }

    static bool checkSarleon(std::shared_ptr<Warrior> const &warrior) {
        return checkSarleonArcher(warrior) || checkSarleonHorseman(warrior) || checkSarleonInfantry(warrior);
    }
};

TEST_F(SarleonWarriorFactoryTest, CheckNotNulls) {
    EXPECT_NE(factory->createArcher(), nullptr);
    EXPECT_NE(factory->createInfantryman(), nullptr);
    EXPECT_NE(factory->createHorseman(), nullptr);
}

TEST_F(SarleonWarriorFactoryTest, CheckTypes) {
    EXPECT_PRED1(checkSarleon, factory->createHorseman());
    EXPECT_PRED1(checkSarleon, factory->createArcher());
    EXPECT_PRED1(checkSarleon, factory->createInfantryman());

    EXPECT_PRED1(checkSarleonArcher, factory->createArcher());
    EXPECT_PRED1(checkSarleonHorseman, factory->createHorseman());
    EXPECT_PRED1(checkSarleonInfantry, factory->createInfantryman());
}