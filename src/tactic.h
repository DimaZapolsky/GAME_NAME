//
// Created by Dima Zapolsky on 10/05/2019.
//

#ifndef GAME_TACTIC_H
#define GAME_TACTIC_H

#include <string>
#include <memory>
class Warrior;

class Tactic{
public:
    enum AttackType {
        Rear, Front
    };

    enum TacticAction: int {
        Attack, Defense
    };

    enum TacticWarrior: int {
        Archer, Horseman, Infantryman, all
    };

    Tactic(TacticWarrior warrior, TacticAction action, AttackType attackType, TacticWarrior target) : warrior(warrior),
    action(action), attackType(attackType), target(target) {};
    bool canAttack(std::shared_ptr<Warrior> warrior);
    bool includes(std::shared_ptr<Warrior> warrior1);

protected:
    AttackType attackType; // 'Rear' or 'Front'
    TacticAction action; // 'Attack' or 'Defense'
    TacticWarrior warrior; // 'archer' or 'horseman' or 'infantryman' or 'all'
    TacticWarrior target; // 'archer' or 'horseman' or 'infantryman' or 'all'
};

#endif //GAME_TACTIC_H
