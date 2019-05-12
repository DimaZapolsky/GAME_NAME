//
// Created by Dima Zapolsky on 2019/05/12.
//

#ifndef GAME_ILEADERNAMEGENERATOR_H
#define GAME_ILEADERNAMEGENERATOR_H

#include <string>

class ILeaderNameGenerator {
public:
    virtual std::string generateLeaderName() = 0;
};

#endif //GAME_ILEADERNAMEGENERATOR_H
