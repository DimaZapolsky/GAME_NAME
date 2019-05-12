//
// Created by Dima Zapolsky on 10/05/2019.
//

#include "tactic.h"
#include "functions.h"
#include "warrior.h"
#include "warriorType.h"

bool Tactic::canAttack(std::shared_ptr<Warrior> warrior) {
    if (action == TacticAction::Defense) {
        return false;
    }
    if (target == TacticWarrior::all) {
        return true;
    }
    if (target == TacticWarrior::Archer) {
        return isArcher(std::move(warrior));
    }
    if (target == TacticWarrior::Horseman) {
        return isHorseman(std::move(warrior));
    }
    if (target == TacticWarrior::Infantryman) {
        return isInfantryman(std::move(warrior));
    }
    return false;
}

bool Tactic::includes(std::shared_ptr<Warrior> warrior1) {
    if (this->warrior == all) {
        return true;
    }
    if (this->warrior == Tactic::Archer && warrior1->getType() == TArcher) {
        return true;
    }
    if (this->warrior == Tactic::Horseman && warrior1->getType() == THorseman) {
        return true;
    }
    if (this->warrior == Tactic::Infantryman && warrior1->getType() == TInfantryman) {
        return true;
    }
    return false;

}