//
// Created by Dima Zapolsky on 2019/05/12.
//

#include "battleSearcher.h"
#include "../Random/random.h"
#include "../leader.h"

std::shared_ptr<Army> BattleSearcher::getCurrentEnemy() const {
    return this->currentEnemyArmy;
}

void BattleSearcher::setCurrentEnemy(std::shared_ptr<Army> army) {
    this->currentEnemyArmy = army;
}

void BattleSearcher::battleHasEnded() {
    this->currentEnemyArmy = nullptr;
}

Kingdom BattleSearcher::getEnemyKingdom() {
    return Kingdom(this->player->getKingdom() ^ 1);
}

int BattleSearcher::countArmiesFor(Kingdom kingdom) {
    int cnt = 0;
    for (auto &army : this->wanderingArmies) {
        if (army->getLeader()->getKingdom() == kingdom) {
            cnt++;
        }
    }
    return cnt;
}

std::shared_ptr<Army> BattleSearcher::requestEnemyArmy(std::shared_ptr<Army> forbiddenArmy = nullptr) {
    int cntTries = 0;
    while (true) {
        cntTries++;
        int rnd = rand() % this->wanderingArmies.size();
        if (this->wanderingArmies[rnd]->getLeader()->getKingdom() != this->player->getKingdom() &&
            this->wanderingArmies[rnd] != forbiddenArmy) {
            return this->wanderingArmies[rnd];
        }

        if (cntTries > 200) {
            return nullptr;
        }
    }
}

std::shared_ptr<Army> BattleSearcher::requestAlliedArmy(std::shared_ptr<Army> forbidenArmy = nullptr) {
    int cntTries = 0;
    while (cntTries <= 200) {
        cntTries++;
        int rnd = rand() % this->wanderingArmies.size();
        if (this->wanderingArmies[rnd]->getLeader()->getKingdom() == this->player->getKingdom() &&
        this->wanderingArmies[rnd] != forbidenArmy) {
            return this->wanderingArmies[rnd];
        }
    }
    return nullptr;
}

void BattleSearcher::setPlayer(std::shared_ptr<Leader> player) {
    this->player = player;
}

void BattleSearcher::setWanderingArmies(std::vector<std::shared_ptr<Army>> &armies) {
    this->wanderingArmies = armies;
}

BattleSearcherResponse BattleSearcher::requestNewEvent() {
    if (currentEnemyArmy == nullptr) {
        return requestNewEvent(false, nullptr);
    } else {
        return requestNewEvent(true, currentEnemyArmy);
    }
}

BattleSearcherResponse BattleSearcher::requestNewEvent(bool didFoundBattle, std::shared_ptr<Army> currentEnemyArmy) {
    if (!didFoundBattle) {
        double nothingHappenedProb = 0.4;
        if (randDouble() <= nothingHappenedProb) {
            return BattleSearcherResponse(battleSearcherEnum::NothingHappened, nullptr);
        }
        {
            double randProb = randDouble();
            double incomingAttackProb = 1 - (double) 1 / this->player->getHonor();
            if (incomingAttackProb >= randProb && countArmiesFor(getEnemyKingdom())) {
                return BattleSearcherResponse(battleSearcherEnum::IncomingAttack,
                                              requestEnemyArmy(std::shared_ptr<Army>()));
            }
        }

        {
            double foundedWhatToAttackProb = 1;

            if (randDouble() <= foundedWhatToAttackProb) {
                return BattleSearcherResponse(battleSearcherEnum::FoundArmyToAttack, requestEnemyArmy(
                        std::shared_ptr<Army>()));
            }
        }
    } else {

        double joinEnemyArmy = 0.12 - player->getHonor() / 10000 * 4;
        if (randDouble() <= joinEnemyArmy) {
            auto enemyArmy = requestEnemyArmy(currentEnemyArmy);
            if (enemyArmy == nullptr) {
                return BattleSearcherResponse(battleSearcherEnum::NothingHappened, nullptr);
            }
            return BattleSearcherResponse(battleSearcherEnum::ArmyJoinedApponentSide, requestEnemyArmy(currentEnemyArmy));
        }

        double joinAllyArmy = 0.12 + player->getHonor() / 10000 * 4;
        if (randDouble() <= joinAllyArmy) {
            auto allyArmy = requestAlliedArmy();
            if (allyArmy == nullptr) {
                return BattleSearcherResponse(battleSearcherEnum::NothingHappened, nullptr);
            }
            return BattleSearcherResponse(battleSearcherEnum::ArmyJoinedYourSide, allyArmy);
        }
    }
    return BattleSearcherResponse(battleSearcherEnum::NothingHappened, nullptr);
}