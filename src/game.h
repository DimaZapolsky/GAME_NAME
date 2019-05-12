//
// Created by Dima Zapolsky on 09/05/2019.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "Kingdom.h"
#include "leader.h"
#include "factories/warriorFactory.h"
#include "commandManager.h"
#include "BattlesSearcher/battleSearcher.h"
#include "battleFactory.h"

class Game {
private:
    static Game * instance;

    Game();
    Game( const Game& );
    Game& operator=( Game& ) = default;

    std::vector<std::shared_ptr<Army>> armiesList;
    std::shared_ptr<Leader> player = nullptr;
    std::shared_ptr<WarriorFactory> playerFactory = nullptr;
    std::shared_ptr<WarriorFactory> enemyFactory = nullptr;

    std::shared_ptr<IBattleSearcher> battleSearcher;
    std::shared_ptr<BattleFactory> battleFactory;

    int hardness = -1;
    int steps = 0;
    void setUpHardness();
    int stepsPerDay = 10;
    std::shared_ptr<CommandManager> commandManager = nullptr;

public:
    static Game * getInstance();

    void setUp();
    void clear();
    int getHardness();
    void start();
    void getArmyInfo();
    void reorganizeArmy();
    void checkForPaying();
    void checkForFood();
    void checkNewDay();
    void payForArmy();
    void buyFood();
    void searchForEnemy();
    void train();
    void buyEquipment();
    std::shared_ptr<Leader> getPlayer();
    void addWarrior();
};

#endif //GAME_GAME_H
