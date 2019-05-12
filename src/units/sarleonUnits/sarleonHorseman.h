//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_SARLEONHORSEMAN_H
#define GAME_SARLEONHORSEMAN_H

#include "../horseman.h"

class SarleonHorseman : public Horseman {
public:
    ~SarleonHorseman() = default;
    SarleonHorseman();
    std::string getName() const override;
};

#endif //GAME_SARLEONHORSEMAN_H
