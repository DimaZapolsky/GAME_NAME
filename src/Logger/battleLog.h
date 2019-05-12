//
// Created by Dima Zapolsky on 2019/05/11.
//

#ifndef GAME_BATTLELOG_H
#define GAME_BATTLELOG_H

#include <string>
#include "../warrior.h"


class IBattle_log {
public:
    virtual std::string string_repr() const = 0;
    virtual std::string get_victim() const = 0;
    virtual std::string get_predator() const = 0;
    virtual int get_tick() const = 0;
};

class Battle_log: public IBattle_log {
private:
    std::string victim;
    std::string predator;
    int tick;

public:
    Battle_log(std::shared_ptr<Warrior> const &victim, std::shared_ptr<Warrior> const &predator, int tick);
    std::string string_repr() const override ;
    std::string get_victim() const override ;
    std::string get_predator() const override ;
    int get_tick() const override ;
};

#endif //GAME_BATTLELOG_H
