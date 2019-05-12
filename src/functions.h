//
// Created by Dima Zapolsky on 11/05/2019.
//

#ifndef GAME_FUNCTIONS_H
#define GAME_FUNCTIONS_H


#include "warrior.h"
#include "Kingdom.h"

template<typename Base, typename T>
inline bool instanceof(const T *ptr);

Kingdom getTeam(std::shared_ptr<Warrior> warrior);

bool isArcher(std::shared_ptr<Warrior> warrior);

bool isInfantryman(std::shared_ptr<Warrior> warrior);

bool isHorseman(std::shared_ptr<Warrior> warrior);

bool strip(std::string &s);

bool tolower(std::string &s);


#endif //GAME_FUNCTIONS_H
