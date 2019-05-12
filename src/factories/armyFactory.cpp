//
// Created by Dima Zapolsky on 2019/05/12.
//

#include <random>
#include "armyFactory.h"

std::shared_ptr<Army> ArmyFactory::generateArmy() {
    Army* army = new Army();
    if (leaderFactory == nullptr || sarleonSquadFactory == nullptr || ravensternSquadFactory == nullptr) {
        throw std::exception();
    }

    auto leader = leaderFactory->generateLeader();
    int squadAmount;
    squadAmount = int(leader->getHonor() * 5 * double(rand() % 40 + 80) / (100));

    if (leader->getKingdom() == Kingdom::Sarleon) {
        army->setArmy(sarleonSquadFactory->generateSquad(squadAmount));
    } else {
        army->setArmy(ravensternSquadFactory->generateSquad(squadAmount));
    }
    army->setLeader(leader);
    army->setMoney(leader->getHonor() * (75 + rand() % 51));
    army->addFood(army->getCanCarry() * (40 + rand() % 61) / 100);

    auto armyPtr = std::shared_ptr<Army>(army);
    leader->setArmy(armyPtr);
    return armyPtr;
}

std::vector<std::shared_ptr<Army>> ArmyFactory::generateArmies(int amount) {
    std::vector<std::shared_ptr<Army>> armies;
    armies.reserve(amount);
    for (int i = 0; i < amount; ++i) {
        armies.push_back(generateArmy());
    }
    return armies;
}

void ArmyFactory::setLeaderFactory(std::shared_ptr<ILeaderFactory> leaderGenerator) {
    this->leaderFactory = leaderGenerator;
}

void ArmyFactory::setRavensternSquadFactory(std::shared_ptr<ISquadFactory> squadGenerator) {
    this->ravensternSquadFactory = squadGenerator;
}

void ArmyFactory::setSarleonSquadFactory(std::shared_ptr<ISquadFactory> squadGenerator) {
    this->sarleonSquadFactory = squadGenerator;
}