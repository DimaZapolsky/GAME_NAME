//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_IBATTLESEARCHER_H
#define GAME_IBATTLESEARCHER_H

#include "battleSearcherResponse.h"

class IBattleSearcher : public IEndBattleObserver {
protected:
    virtual BattleSearcherResponse requestNewEvent(bool didFoundBattle, std::shared_ptr<Army> currentEnemyArmy) = 0;

public:
    virtual void setPlayer(std::shared_ptr<Leader> player) = 0;
    //if you starter battle, you should set didFoundBattle=true and currentEnemyArmy, so allies and enemies can join
    virtual BattleSearcherResponse requestNewEvent() = 0;
    virtual void setWanderingArmies(std::vector<std::shared_ptr<Army>> &armies) = 0;
    //virtual void setCurrentEnemyArmy(std::shared_ptr<Army> enemyArmy);
    virtual void battleHasEnded() override = 0;
    virtual void setCurrentEnemy(std::shared_ptr<Army> army) = 0;
    virtual std::shared_ptr<Army> getCurrentEnemy() const = 0;
};

#endif //GAME_IBATTLESEARCHER_H
