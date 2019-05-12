//
// Created by Dima Zapolsky on 2019/05/11.
//

#include "battleLog.h"

Battle_log::Battle_log(std::shared_ptr<Warrior> const &victim, std::shared_ptr<Warrior> const &predator, int tick) {
    this->victim = victim->getName();
    this->predator = predator->getName();
    this->tick = tick;
}

std::string Battle_log::string_repr() const {
    return victim + " has been slain by " + predator;
}

int Battle_log::get_tick() const {
    return tick;
}

std::string Battle_log::get_predator() const {
    return this->predator;
}

std::string Battle_log::get_victim() const {
    return this->victim;
}