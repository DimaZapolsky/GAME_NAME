//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_KINGDOMGENERATOR_H
#define GAME_KINGDOMGENERATOR_H


#include "IKingdomGenerator.h"

class KingdomGenerator: public IKingdomGenerator {
public:
    Kingdom generateKingdom() override ;
};


#endif //GAME_KINGDOMGENERATOR_H
