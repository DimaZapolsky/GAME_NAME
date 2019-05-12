//
// Created by Dima Zapolsky on 2019/05/11.
//

#ifndef GAME_IENDBATTLEOBSERVER_H
#define GAME_IENDBATTLEOBSERVER_H

class IEndBattleObserver {
public:
    virtual void battleHasEnded() = 0;
};

#endif //GAME_IENDBATTLEOBSERVER_H
