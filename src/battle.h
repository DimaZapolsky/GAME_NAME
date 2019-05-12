//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_BATTLE_H
#define GAME_BATTLE_H
#include <vector>
#include "Logger/battleLog.h"
#include "squad.h"
#include "Logger/battle_logger.h"
#include "army.h"
#include "IEndBattleObservable.h"


class IBattle {
public:
    virtual int get_ticks() const = 0;
    virtual std::vector<std::shared_ptr<IBattle_log>> start_war(bool should_log_to_console) = 0;
    virtual void setTactics() = 0;
    virtual void addSubscriber(std::shared_ptr<IEndBattleObserver> subscriber) = 0;

};

class Battle: public IBattle, public IEndBattleObservable {
private:
    int tick = 0;
    std::vector<std::shared_ptr<Army>> squads;
    std::shared_ptr<IBattle_logger> logger;
    terrainEnum terrain;
    std::vector<std::shared_ptr<IEndBattleObserver>> subscribers;
protected:
    void notifyOnBattleEnded() override ;
    void disposeSubscriptions() override ;
public:

    Battle(std::vector<std::shared_ptr<Army>> &squads, std::shared_ptr<IBattle_logger> &logger);
    void setTactics() override ;
    int get_ticks() const override;
    std::vector<std::shared_ptr<IBattle_log>> start_war(bool should_log_to_console) override;
    terrainEnum getTerrain() const;
    void addSubscriber(std::shared_ptr<IEndBattleObserver> subscriber) override ;
};

#endif //GAME_BATTLE_H
