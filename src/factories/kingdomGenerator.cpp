//
// Created by Dima Zapolsky on 2019/05/12.
//

#include <cstdlib>
#include "kingdomGenerator.h"

Kingdom KingdomGenerator::generateKingdom() {
    if (rand() % 2) {
        return Kingdom::Sarleon;
    } else {
        return Kingdom::Ravenstern;
    }
}