//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_SARLEONINFANTRYMAN_H
#define GAME_SARLEONINFANTRYMAN_H

#include "../infantryman.h"

class SarleonInfantryman : public Infantryman {
public:
    ~SarleonInfantryman() = default;
    SarleonInfantryman();
    std::string getName() const override;
};

#endif //GAME_SARLEONINFANTRYMAN_H
