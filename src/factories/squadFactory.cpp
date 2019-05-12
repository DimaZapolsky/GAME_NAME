//
// Created by Dima Zapolsky on 2019/05/12.
//

#include "squadFactory.h"
#include "../game.h"

std::shared_ptr<Squad> SquadFactory::generateSquad(int amount) {
    if (warriorFactory == nullptr) {
        throw std::exception();
    }
    auto squad = std::make_shared<Squad>();
    int p = 10 * (Game::getInstance()->getHardness() + 1);
    for (int i = 0; i < amount; ++i) {
        int rnd = rand() % 10;
        std::shared_ptr<Warrior> warrior;
        if (rnd < 3) {
            warrior = std::move(warriorFactory->createArcher());
            //squad->add(warriorFactory->createArcher());
        }
        else if (rnd < 5) {
            warrior = std::move(warriorFactory->createHorseman());
            //squad->add(warriorFactory->createHorseman());
        }
        else {
            warrior = std::move(warriorFactory->createInfantryman());
            //squad->add(warriorFactory->createInfantryman());
        }
        for (int i = 0; i < 4; ++i) {
            if (rand() % 100 < p) {
                warrior->upSkillLevel(false);
            }
            else {
                break;
            }
        }
        for (int i = 0; i < 4; ++i) {
            if (rand() % 100 < p) {
                warrior->upEquipmentLevel(false);
            }
            else {
                break;
            }
        }
        squad->add(warrior);
    }
    return squad;
}

void SquadFactory::setWarriorsFactory(std::shared_ptr<WarriorFactory> factory) {
    this->warriorFactory = factory;
}