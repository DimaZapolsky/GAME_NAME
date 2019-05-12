//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_IENDBATTLEOBSERVABLE_H
#define GAME_IENDBATTLEOBSERVABLE_H

class IEndBattleObservable {
protected:
    virtual void notifyOnBattleEnded() = 0;
    virtual void disposeSubscriptions() = 0;
};

#endif //GAME_IENDBATTLEOBSERVABLE_H
