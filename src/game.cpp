//
// Created by Dima Zapolsky on 09/05/2019.
//

#include "game.h"
#include "includes/allFactories.h"
#include <iostream>
#include <typeinfo>
#include "functions.h"
#include "armyFactoryAssembly.h"
#include "battleFactory.h"

Game* Game::instance = nullptr;

Game * Game::getInstance() {
    if(!instance)
        instance = new Game();
    return instance;
}

void Game::clear() {
    player = nullptr;
    enemyFactory = nullptr;
    playerFactory = nullptr;
    hardness = -1;
}

void Game::setUpHardness() {
    std::cout << "Выберите сложность (0 - легко, 1 - средне, 2 - сложно)" << std::endl;
    while (std::cin >> hardness && hardness != 1 && hardness != 2 && hardness != 0) {
        std::cout << "Что-то на эльфийском, не могу разобрать. Попробуйте еще раз" << std::endl;
    }
}

int Game::getHardness() {
    return hardness;
}

void Game::start() {
    clear();
    player = std::make_shared<Leader>();
    setUpHardness();
    setUp();//setup armies
    player->setByUser();
    if (player->getKingdom() == Kingdom::Ravenstern) {
        playerFactory = std::make_shared<RavensternWarriorFactory>();
        enemyFactory = std::make_shared<SarleonWarriorFactory>();
    }
    else if (player->getKingdom() == Kingdom::Sarleon) {
        enemyFactory = std::make_shared<RavensternWarriorFactory>();
        playerFactory = std::make_shared<SarleonWarriorFactory>();
    }
    //this->battleFactory->
    this->battleSearcher->setPlayer(player);

    std::cout << "Введите help чтобы узнать список доступных комманд" << std::endl;
    commandManager = std::shared_ptr<CommandManager>();
    commandManager->start();
;}

void Game::getArmyInfo() {
    std::cout <<  player->getArmyInfo() << std::endl;
}

void Game::reorganizeArmy() {
    steps++;
    player->reorganizeArmy();
    checkNewDay();
}

void Game::checkForPaying() {
    if (player->payForArmy()) {
        std::cout << "LOL, YOU DIED!" << std::endl;
        exit(0);
    }
}

void Game::checkForFood() {
    if (player->foodForArmy()) {
        std::cout << "LOL, YOU DIED!" << std::endl;
        exit(0);
    }
}

void Game::checkNewDay() {
    if (steps % stepsPerDay == 0) {
        std::cout << "И снова новый день!!!" << std::endl;
        checkForFood();
        checkForPaying();
        if (steps % (7 * stepsPerDay) == 0) {
            player->increaseUnpayedWeeks();
        }
    }
}

void Game::payForArmy() {
    int max_weeks_can_pay = player->getUnpayedWeeks();
    if (player->getArmyCost() == 0 || player->getUnpayedWeeks() == 0) {
        std::cout << "Вам не надо ничего платить" << std::endl;
        return;
    }
    max_weeks_can_pay = std::min(max_weeks_can_pay, player->getMoney() / player->getArmyCost());
    if (max_weeks_can_pay == 0) {
        std::cout << "У вас не хватает денег, чтобы заплатить армии:(" << std::endl;
        return;
    }
    else {
        std::cout << "Вы можете заплатить армии максимум за " << max_weeks_can_pay << " недель." << std::endl;
        std::cout << "Введите количество недель, за которые хотите заплатить" << std::endl;
        int a;
        while (std::cin >> a && (a < 0 || a > max_weeks_can_pay)) {
            std::cout << "Что-то не так. Попробуйте еще раз" << std::endl;
        }
        player->payArmy(a);
        std::cout << "Вы заплатили армии. Денег осталось: " << player->getMoney() << std::endl;
    }
}

int getFoodCost(int charisma) {
    int ans = 28 + rand() % 5;
    ans -= ans * charisma / 40;
    return ans;
}

void Game::buyFood() {
    steps++;
    int foodCost = getFoodCost(player->getCharisma());
    foodCost = (foodCost * (180 + rand() % 41)) / 200;
    std::cout << "Стоимость еды: " << foodCost << " монет/10 шт" << std::endl;
    int can_max_buy = std::min(player->getCanCarry() - player->getFoodCnt(), 10 * player->getMoney() / foodCost);
    std::cout << "Вы можете максимум купить: " << can_max_buy << std::endl;
    int a;
    std::cout << "Введите сколько вы хотите купить" << std::endl;
    while (std::cin >> a && (a < 0 || a > can_max_buy)) {
        std::cout << "Что-то не так. Попробуйте еще раз" << std::endl;
    }
    player->decreaseMoney(a * foodCost / 10);
    std::cout << "Вы заплатили: " << (a * foodCost) / 10 << std::endl;
    player->addFood(a);
    checkNewDay();
}

void Game::searchForEnemy() {
    steps++;
    auto response = this->battleSearcher->requestNewEvent();
    if (response.getEventType() == battleSearcherEnum::NothingHappened) {
        std::cout << "Ничего не произошло" << std::endl;
    }
    else if (response.getEventType() == battleSearcherEnum::IncomingAttack) {
        auto firstEnemyArmy = response.getArmy();
        this->battleSearcher->setCurrentEnemy(firstEnemyArmy);
        std::vector<std::shared_ptr<Army>> currentArmies;
        currentArmies.push_back(this->player->getArmy());
        currentArmies.push_back(firstEnemyArmy);

        auto battle = this->battleFactory->createBattle(currentArmies);
        battle->addSubscriber(this->battleSearcher);
        battle->start_war(true);

        /*auto joiningArmiesReponse = this->battleSearcher->requestNewEvent();
        if (joiningArmiesReponse.getEventType() == ArmyJoinedYourSide) {
            std::cout << "К вам присоединилась армия под руководством " + joiningArmiesReponse.getArmy()->getLeader()->getName() + "\n";
            std::cout << "Описание союзной армии\n";
            std::cout << joiningArmiesReponse.getArmy()->getInfo() << std::endl;
        }*/
    } else if (response.getEventType() == battleSearcherEnum::FoundArmyToAttack) {
        std::cout << "Вы хотите атаковать армию под руководством " + response.getArmy()->getLeader()->getName() + "?(y - да, n - нет)";
        std::cout << "Описание армии\n";
        std::cout << response.getArmy()->getInfo();

        std::string userAnswer;
        std::cin >> userAnswer;
        if (!userAnswer.empty() && userAnswer[0] == 'y') {
            std::vector<std::shared_ptr<Army>> currentArmies;
            currentArmies.push_back(this->player->getArmy());
            currentArmies.push_back(response.getArmy());
            auto joiningArmiesResponse = this->battleSearcher->requestNewEvent();
            if (joiningArmiesResponse.getEventType() == ArmyJoinedYourSide) {
                std::cout << "К вам присоединилась армия под руководством " + joiningArmiesResponse.getArmy()->getLeader()->getName() + "\n";
                std::cout << "Описание союзной армии\n";
                std::cout << joiningArmiesResponse.getArmy()->getInfo() << std::endl;
                currentArmies.push_back(joiningArmiesResponse.getArmy());
            }
            if (joiningArmiesResponse.getEventType() == ArmyJoinedApponentSide) {
                std::cout << "К врагу присоединилась армия под руководством " + joiningArmiesResponse.getArmy()->getLeader()->getName() + "\n";
                std::cout << "Описание вражеской армии\n";
                std::cout << joiningArmiesResponse.getArmy()->getInfo() << std::endl;
                currentArmies.push_back(joiningArmiesResponse.getArmy());
            }
            auto battle = this->battleFactory->createBattle(currentArmies);
            battle->addSubscriber(this->battleSearcher);

            battle->start_war(true);
        }
    }
    checkNewDay();
}

void Game::train() {
    player->train();
    for (int i = 0; i < 10; ++i) {
        steps++;
        checkNewDay();
    }
}

void Game::buyEquipment() {
    steps++;
    player->buyEquipment();
    checkNewDay();
}

Game::Game() {
    this->battleSearcher = std::shared_ptr<BattleSearcher>(new BattleSearcher());
    this->battleFactory = std::shared_ptr<BattleFactory>(new BattleFactory());
}

std::shared_ptr<Leader> Game::getPlayer() {
    return player;
}

void Game::addWarrior() {
    auto infantryman = playerFactory->createInfantryman();
    auto archer = playerFactory->createArcher();
    auto horseman = playerFactory->createHorseman();
    int money = player->getMoney();
    if (money < std::min(archer->getCost(), std::min(infantryman->getCost(), horseman->getCost()))) {
        std::cout << "У вас недостаточно денег чтобы купить война" << std::endl;
        return;
    }
    std::cout << "Стоимость лучника: " << archer->getCost() << std::endl;
    std::cout << "Стоимость кавалериста: " << horseman->getCost() << std::endl;
    std::cout << "Стоимость пехотинца: " << infantryman->getCost() << std::endl;
    std::cout << "Введите кого хотите нанять (Лучник - A/a, Кавалерист - H/h, Пехотинец - I/i)" << std::endl;
    char c;
    while (std::cin >> c) {
        c = tolower(c);
        if (c == 'a') {
            if (money < archer->getCost()) {
                std::cout << "Недостаточно средств" << std::endl;
            }
            else {
                player->addWarrior(archer);
                player->decreaseMoney(archer->getCost());
                std::cout << "Вы наняли нового воина" << std::endl;
            }
            break;
        }
        else if (c == 'h') {
            if (money < horseman->getCost()) {
                std::cout << "Недостаточно средств" << std::endl;
            }
            else {
                player->addWarrior(horseman);
                player->decreaseMoney(horseman->getCost());
                std::cout << "Вы наняли нового воина" << std::endl;
            }
            break;
        }
        else if (c == 'i') {
            if (money < infantryman->getCost()) {
                std::cout << "Недостаточно средств" << std::endl;
            }
            else {
                player->addWarrior(infantryman);
                player->decreaseMoney(infantryman->getCost());
                std::cout << "Вы наняли нового воина" << std::endl;
            }
            break;
        }
        else {
            std::cout << "Такого варианта нет:(" << std::endl;
        }
    }
}

void Game::setUp() {
    auto factory = ArmyFactoryAssembly().getArmyFactory();
    armiesList = factory->generateArmies(100);

    this->battleSearcher->setPlayer(this->player);
    this->battleSearcher->setWanderingArmies(this->armiesList);
}