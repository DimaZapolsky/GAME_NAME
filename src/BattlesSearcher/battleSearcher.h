//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_BATTLESEARCHER_H
#define GAME_BATTLESEARCHER_H


#include "IBattleSearcher.h"
#include "../Kingdom.h"

class BattleSearcher: public IBattleSearcher {
private:
    std::vector<std::shared_ptr<Army>> wanderingArmies;
    std::shared_ptr<Leader> player;
    std::shared_ptr<Army> requestEnemyArmy(std::shared_ptr<Army> forbiddenArmy);
    std::shared_ptr<Army> requestAlliedArmy(std::shared_ptr<Army> forbidenArmy);
    std::shared_ptr<Army> currentEnemyArmy;
    int countArmiesFor(Kingdom kingdom);
    Kingdom getEnemyKingdom();

protected:
    BattleSearcherResponse requestNewEvent(bool didFoundBattle, std::shared_ptr<Army> currentEnemyArmy) override ;
public:
    void setPlayer(std::shared_ptr<Leader> player) override ;
    void setWanderingArmies(std::vector<std::shared_ptr<Army>> &armies) override ;
    std::shared_ptr<Army> getCurrentEnemy() const override ;
    BattleSearcherResponse requestNewEvent() override ;
    void battleHasEnded() override;
    void setCurrentEnemy(std::shared_ptr<Army> army) override ;
};


#endif //GAME_BATTLESEARCHER_H
