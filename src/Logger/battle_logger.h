//
// Created by Dima Zapolsky on 2019/05/11.
//

#ifndef GAME_BATTLE_LOGGER_H
#define GAME_BATTLE_LOGGER_H


#include "battleLog.h"
#include "../IEndBattleObserver.h"

class IBattle_logger: public IEndBattleObserver {
public:
    virtual void addLog(std::shared_ptr<IBattle_log> const &single_log) = 0;
    virtual std::vector<std::shared_ptr<IBattle_log>> getLogs() = 0;
    virtual std::string getStringLogs() = 0;
    virtual void battleHasEnded() override = 0;
};

class Battle_logger: public IBattle_logger {
private:
    std::vector<std::shared_ptr<IBattle_log>> logs;
public:
    void addLog(std::shared_ptr<IBattle_log> const &single_log) override ;
    std::vector<std::shared_ptr<IBattle_log>> getLogs() override ;
    std::string getStringLogs() override ;
    void battleHasEnded() override;
};


#endif //GAME_BATTLE_LOGGER_H
