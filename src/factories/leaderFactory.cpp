//
// Created by Dima Zapolsky on 2019/05/12.
//

#include <random>
#include "leaderFactory.h"

std::shared_ptr<Leader> LeaderFactory::generateLeader() {
    std::default_random_engine generator;
    std::normal_distribution<int> distribution(25, 10);
    int honor = distribution(generator);
    honor = std::max(honor, 1);
    int strat = rand() % 7;
    int charisma = rand() % 7;
    int coaching = 15 - strat - charisma;
    if (nameGenerator == nullptr || kingdomGenerator == nullptr) {
        throw std::exception();
    }
    auto leader = std::shared_ptr<Leader>(new Leader(nameGenerator->generateLeaderName(), kingdomGenerator->generateKingdom(), honor, strat, charisma, coaching));
    return leader;
}

void LeaderFactory::setNameGenerator(std::shared_ptr<ILeaderNameGenerator> nameGenerator) {
    this->nameGenerator = nameGenerator;
}

void LeaderFactory::setKingdomGenerator(std::shared_ptr<IKingdomGenerator> kingdomGen) {
    this->kingdomGenerator = kingdomGen;
}