//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_SARLEONARCHER_H
#define GAME_SARLEONARCHER_H

#include "../archer.h"

class SarleonArcher : public Archer {
public:
    ~SarleonArcher() = default;
    SarleonArcher();
    std::string getName() const override;
};

#endif //GAME_SARLEONARCHER_H
