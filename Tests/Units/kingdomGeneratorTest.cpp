//
// Created by Dima Zapolsky 2019/05/12.
//

#include <gtest/gtest.h>
#include "../../src/factories/IKingdomGenerator.h"
#include "../../src/factories/kingdomGenerator.h"

class KingdomGeneratorTest: public ::testing::Test {
protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {

    }

    std::shared_ptr<IKingdomGenerator> generator;

public:
    KingdomGeneratorTest() : Test() {
        generator = std::shared_ptr<IKingdomGenerator>(new KingdomGenerator());
    }
};

TEST_F(KingdomGeneratorTest, generatesValue) {
    EXPECT_NO_THROW(generator->generateKingdom());
}