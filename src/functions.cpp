//
// Created by Dima Zapolsky on 11/05/2019.
//

#include "functions.h"
#include "includes/allUnits.h"
#include "includes/allUnits.h"

template<typename Base, typename T>
inline bool instanceof(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

Kingdom getTeam(std::shared_ptr<Warrior> warrior) {
    if (instanceof<RavensternInfantryman>(warrior.get()) || instanceof<RavensternHorseman>(warrior.get()) || instanceof<RavensternArcher>(warrior.get())) {
        return Ravenstern;
    }
    else if (instanceof<SarleonInfantryman>(warrior.get()) || instanceof<SarleonHorseman>(warrior.get()) || instanceof<SarleonArcher>(warrior.get())) {
        return Sarleon;
    }
}

bool isArcher(std::shared_ptr<Warrior> warrior) {
    return instanceof<Archer>(warrior.get());
}

bool isInfantryman(std::shared_ptr<Warrior> warrior) {
    return instanceof<Infantryman>(warrior.get());
}

bool isHorseman(std::shared_ptr<Warrior> warrior) {
    return instanceof<Horseman>(warrior.get());
}

bool strip(std::string &s) {
    while (s.size() > 0 && s.back() == ' ') {
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    while (s.size() > 0 && s.back() == ' ') {
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    return true;
}

bool tolower(std::string &s) {
    for (auto & c : s) {
        c = tolower(c);
    }
    return true;
}
