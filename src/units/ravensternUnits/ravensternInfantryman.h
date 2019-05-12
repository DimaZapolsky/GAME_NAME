//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_RAVENSTERNINFANTRYMAN_H
#define GAME_RAVENSTERNINFANTRYMAN_H

#include "../infantryman.h"

class RavensternInfantryman : public Infantryman {
public:
    ~RavensternInfantryman() = default;
    RavensternInfantryman();
    std::string getName() const override;
};

#endif //GAME_RAVENSTERNINFANTRYMAN_H
