#include <iostream>
#include <gtest/gtest.h>
#include "game.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        Game * game = Game::getInstance();
        game->start();
        std::cout << "Прощайте!" << std::endl;
        return 0;
    } else {
        //std::cout << argc << std::endl << argv[0] << std::endl;
        std::cout << "TESTS\n";

        testing::InitGoogleTest();
        return RUN_ALL_TESTS();
    }
}