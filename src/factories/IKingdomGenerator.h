//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_IKINGDOMGENERATOR_H
#define GAME_IKINGDOMGENERATOR_H

#include "../Kingdom.h"

class IKingdomGenerator {
public:
    virtual Kingdom generateKingdom() = 0;
};

#endif //GAME_IKINGDOMGENERATOR_H
