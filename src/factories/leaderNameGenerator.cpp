//
// Created by Dima Zapolsky on 2019/05/12.
//

#include "leaderNameGenerator.h"

std::string LeaderNameGenerator::generateLeaderName() {
    int randIndex = rand() % this->firstNames.size();
    return this->firstNames[randIndex] + std::to_string(rand());
}