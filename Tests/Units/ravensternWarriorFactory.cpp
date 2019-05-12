//
// Created by Dima Zapolsky 2019/05/12.
//

#include <gtest/gtest.h>
#include "../../src/includes/allFactories.h"
#include "../../src/functions.h"

class RavensternWarriorFactoryTest: public ::testing::Test {
protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {

    }

    std::shared_ptr<RavensternWarriorFactory> factory;

public:
    RavensternWarriorFactoryTest() : Test() {
        factory = std::shared_ptr<RavensternWarriorFactory>(new RavensternWarriorFactory());
    }

    static bool checkRavenArcher(std::shared_ptr<Warrior> const &warrior) {
        return instanceof<RavensternArcher>(warrior.get());
    }

    static bool checkRavenInfantry(std::shared_ptr<Warrior> const &warrior) {
        return instanceof<RavensternInfantryman>(warrior.get());
    }

    static bool checkRavenHorseman(std::shared_ptr<Warrior> const &warrior) {
        return instanceof<RavensternHorseman>(warrior.get());
    }

    static bool checkRaven(std::shared_ptr<Warrior> const &warrior) {
        return checkRavenArcher(warrior) || checkRavenHorseman(warrior) || checkRavenInfantry(warrior);
    }
};

TEST_F(RavensternWarriorFactoryTest, CheckNotNulls) {
    EXPECT_NE(factory->createArcher(), nullptr);
    EXPECT_NE(factory->createInfantryman(), nullptr);
    EXPECT_NE(factory->createHorseman(), nullptr);
}

TEST_F(RavensternWarriorFactoryTest, CheckTypes) {
    EXPECT_PRED1(checkRaven, factory->createHorseman());
    EXPECT_PRED1(checkRaven, factory->createArcher());
    EXPECT_PRED1(checkRaven, factory->createInfantryman());

    EXPECT_PRED1(checkRavenArcher, factory->createArcher());
    EXPECT_PRED1(checkRavenHorseman, factory->createHorseman());
    EXPECT_PRED1(checkRavenInfantry, factory->createInfantryman());
}