//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_RAVENSTERNARCHER_H
#define GAME_RAVENSTERNARCHER_H

#include "../archer.h"

class RavensternArcher : public Archer {
public:
    ~RavensternArcher() = default;
    RavensternArcher();
    std::string getName() const override;
};

#endif //GAME_RAVENSTERNARCHER_H
