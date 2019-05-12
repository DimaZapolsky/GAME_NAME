//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_RAVENSTERNHORSEMAN_H
#define GAME_RAVENSTERNHORSEMAN_H

#include "../horseman.h"

class RavensternHorseman : public Horseman {
public:
    ~RavensternHorseman() = default;
    RavensternHorseman();
    std::string getName() const override;
};

#endif //GAME_RAVENSTERNHORSEMAN_H
