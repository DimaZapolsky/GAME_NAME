//
// Created by Dima Zapolsky 2019/05/12.
//

#include <gtest/gtest.h>
#include "../../src/factories/ISquadFactory.h"
#include "../../src/includes/allFactories.h"
#include "../../src/factories/squadFactory.h"

class SquadFactoryTest: public ::testing::Test {
protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {
    }

    std::shared_ptr<ISquadFactory> squadFactory;
    std::shared_ptr<WarriorFactory> warriorFactory;

public:
    SquadFactoryTest() : Test() {
        warriorFactory = std::shared_ptr<WarriorFactory>(new SarleonWarriorFactory());
        squadFactory = std::shared_ptr<ISquadFactory>(new SquadFactory());
        //generatedSquads = 10;
    }

    void configure() {
        squadFactory->setWarriorsFactory(warriorFactory);
    }
    int generatedSquads = 10;
};

TEST_F(SquadFactoryTest, Throw) {
    EXPECT_THROW(squadFactory->generateSquad(10), std::exception);
}

TEST_F(SquadFactoryTest, NoThrow) {
    configure();
    EXPECT_NO_THROW(squadFactory->generateSquad(10));
}

TEST_F(SquadFactoryTest, generatedSize) {
    configure();
    EXPECT_EQ(squadFactory->generateSquad(generatedSquads)->getAllWarriors().size(), generatedSquads);
}

