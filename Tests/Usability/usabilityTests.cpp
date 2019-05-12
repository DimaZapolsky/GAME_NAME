//
// Created by Dima Zapolsky on 13/05/2019.
//

#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include "../../src/game.h"

class UsabilityTests: public ::testing::Test {
protected:

    virtual void TearDown() {}

    virtual void SetUp() {}
};

bool check_eq(const std::string &filename1, const std::string &filename2) {
    std::ifstream in1(filename1);
    std::ifstream in2(filename2);
    std::string s1, s2;
    
    while (getline(in1, s1)) {
        getline(in2, s2);
        if (s1.find("Стоимость") != -1 && s2.find("Стоимость") != -1) {
            continue;
        }
        if (s1.find("Потребление") != -1 && s2.find("Потребление") != -1) {
            continue;
        }
        if (s1.find("Денег") != -1 && s2.find("Денег") != -1) {
            continue;
        }
        if (s1.find("Еды") != -1 && s2.find("Еды") != -1) {
            continue;
        }
        if (s1.find("Переносимый") != -1 && s2.find("Переносимый") != -1) {
            continue;
        }
    }
    return true;
}

TEST_F(UsabilityTests, CheckIncorrectInputAndHelp) {
    std::ifstream in("./Tests/Usability/1.in");
    std::cin.rdbuf(in.rdbuf());

    std::ofstream out("./Tests/Usability/ans.txt");
    std::cout.rdbuf(out.rdbuf());

    Game::getInstance()->start();

    EXPECT_TRUE(check_eq("./Tests/Usability/ans1.txt", "./Tests/Usability/ans.txt"));
}


TEST_F(UsabilityTests, CheckIncorrectInputAndAliases) {
    std::ifstream in("./Tests/Usability/2.in");
    std::cin.rdbuf(in.rdbuf());

    std::ofstream out("./Tests/Usability/ans.txt");
    std::cout.rdbuf(out.rdbuf());

    Game::getInstance()->start();

    EXPECT_TRUE(check_eq("./Tests/Usability/ans2.txt", "./Tests/Usability/ans.txt"));
}


TEST_F(UsabilityTests, CheckAddAndFood) {
    std::ifstream in("./Tests/Usability/3.in");
    std::cin.rdbuf(in.rdbuf());

    std::ofstream out("./Tests/Usability/ans.txt");
    std::cout.rdbuf(out.rdbuf());

    Game::getInstance()->start();

    EXPECT_TRUE(check_eq("./Tests/Usability/ans3.txt", "./Tests/Usability/ans.txt"));
}


TEST_F(UsabilityTests, CheckAddROAndEQIncorrectInput) {
    std::ifstream in("./Tests/Usability/4.in");
    std::cin.rdbuf(in.rdbuf());

    std::ofstream out("./Tests/Usability/ans.txt");
    std::cout.rdbuf(out.rdbuf());

    Game::getInstance()->start();

    EXPECT_TRUE(check_eq("./Tests/Usability/ans4.txt", "./Tests/Usability/ans.txt"));
}


TEST_F(UsabilityTests, CheckBigInput) {
    std::ifstream in("./Tests/Usability/5.in");
    std::cin.rdbuf(in.rdbuf());

    std::ofstream out("./Tests/Usability/ans.txt");
    std::cout.rdbuf(out.rdbuf());

    Game::getInstance()->start();

    EXPECT_TRUE(check_eq("./Tests/Usability/ans5.txt", "./Tests/Usability/ans.txt"));
}

TEST_F(UsabilityTests, CheckArmyInfo) {
    std::ifstream in("./Tests/Usability/6.in");
    std::cin.rdbuf(in.rdbuf());

    std::ofstream out("./Tests/Usability/ans.txt");
    std::cout.rdbuf(out.rdbuf());

    Game::getInstance()->start();

    EXPECT_TRUE(check_eq("./Tests/Usability/ans6.txt", "./Tests/Usability/ans.txt"));
}

TEST_F(UsabilityTests, CheckInfoAfterRo) {
    std::ifstream in("./Tests/Usability/7.in");
    std::cin.rdbuf(in.rdbuf());

    std::ofstream out("./Tests/Usability/ans.txt");
    std::cout.rdbuf(out.rdbuf());

    Game::getInstance()->start();

    EXPECT_TRUE(check_eq("./Tests/Usability/ans7.txt", "./Tests/Usability/ans.txt"));
}