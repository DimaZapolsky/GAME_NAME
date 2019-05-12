//
// Created by Dima Zapolsky 2019/05/12.
//

#include <gtest/gtest.h>
#include "../../src/factories/ILeaderNameGenerator.h"
#include "../../src/factories/leaderNameGenerator.h"
#include <algorithm>
#include <string>

class LeaderNameGeneratorTest: public ::testing::Test {
protected:
    virtual void TearDown() {

    }

    virtual void SetUp() {

    }

    std::shared_ptr<ILeaderNameGenerator> generator;
public:
    LeaderNameGeneratorTest() : Test() {
        generator = std::shared_ptr<ILeaderNameGenerator>(new LeaderNameGenerator());
    }

    static bool rightFormattedName(std::string const &name) {
        return (name.find_first_of("0123456789") != std::string::npos) && (name.find_first_not_of("0123456789") !=
        std::string::npos) && (name.size() > 1 && isupper(name[0]));
    }
};

TEST_F(LeaderNameGeneratorTest, testGeneration) {
    std::string name = generator->generateLeaderName();
    EXPECT_PRED1(rightFormattedName, name);
}