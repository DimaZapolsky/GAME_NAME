//
// Created by Dima Zapolsky on 12/05/2019.
//

#include "gtest/gtest.h"
#include "../../src/includes/allUnits.h"
#include "../../src/warrior.h"

class unitTest : public ::testing::Test {
protected:
    std::shared_ptr<SarleonArcher> sarleonArcher;
    std::shared_ptr<SarleonHorseman> sarleonHorseman;
    std::shared_ptr<SarleonInfantryman> sarleonInfantryman;
    std::shared_ptr<RavensternInfantryman> ravensternInfantryman;
    std::shared_ptr<RavensternHorseman> ravensternHorseman;
    std::shared_ptr<RavensternArcher> ravensternArcher;

    virtual void TearDown() {
    }

    virtual void SetUp() {
        sarleonArcher = std::shared_ptr<SarleonArcher>(new SarleonArcher());
        sarleonHorseman = std::shared_ptr<SarleonHorseman>(new SarleonHorseman());
        sarleonInfantryman = std::shared_ptr<SarleonInfantryman>(new SarleonInfantryman());
        ravensternArcher = std::shared_ptr<RavensternArcher>(new RavensternArcher());
        ravensternHorseman = std::shared_ptr<RavensternHorseman>(new RavensternHorseman());
        ravensternInfantryman = std::shared_ptr<RavensternInfantryman>(new RavensternInfantryman());
    }
};

TEST_F(unitTest, getNameCheck) {
    EXPECT_EQ(ravensternInfantryman->getName(), "Равенстернский пехотинец (0, 0)");
    EXPECT_EQ(ravensternArcher->getName(), "Равенстернский лучник (0, 0)");
    EXPECT_EQ(ravensternHorseman->getName(), "Равенстернский кавалерист (0, 0)");
    EXPECT_EQ(sarleonInfantryman->getName(), "Сарлеонский пехотинец (0, 0)");
    EXPECT_EQ(sarleonArcher->getName(), "Сарлеонский лучник (0, 0)");
    EXPECT_EQ(sarleonHorseman->getName(), "Сарлеонский кавалерист (0, 0)");
}

TEST_F(unitTest, getTypeCheck) {
    EXPECT_EQ(ravensternHorseman->getType(), THorseman);
    EXPECT_EQ(ravensternInfantryman->getType(), TInfantryman);
    EXPECT_EQ(ravensternArcher->getType(), TArcher);
    EXPECT_EQ(sarleonHorseman->getType(), THorseman);
    EXPECT_EQ(sarleonArcher->getType(), TArcher);
    EXPECT_EQ(sarleonInfantryman->getType(), TInfantryman);
}

TEST_F(unitTest, getParamsFunctionsCheck) {
    EXPECT_TRUE(ravensternArcher->getMaxDistance() <= 100);
    EXPECT_TRUE(ravensternArcher->getAttackSpeed() <= 100);
    EXPECT_TRUE(ravensternArcher->getDamage() <= 100);
    EXPECT_TRUE(ravensternArcher->getAccuracy() <= 100);
    EXPECT_TRUE(sarleonArcher->getMaxDistance() <= 100);
    EXPECT_TRUE(sarleonArcher->getAttackSpeed() <= 100);
    EXPECT_TRUE(sarleonArcher->getDamage() <= 100);
    EXPECT_TRUE(sarleonArcher->getAccuracy() <= 100);

    EXPECT_TRUE(ravensternInfantryman->getDamage() <= 100);
    EXPECT_TRUE(ravensternInfantryman->getSpeed() <= 100);
    EXPECT_TRUE(ravensternInfantryman->getArmor() <= 100);
    EXPECT_TRUE(sarleonInfantryman->getDamage() <= 100);
    EXPECT_TRUE(sarleonInfantryman->getSpeed() <= 100);
    EXPECT_TRUE(sarleonInfantryman->getArmor() <= 100);

    EXPECT_TRUE(ravensternHorseman->getHorseSpeed() <= 100);
    EXPECT_TRUE(ravensternHorseman->getArmor() <= 100);
    EXPECT_TRUE(ravensternHorseman->getDamage() <= 100);
    EXPECT_TRUE(ravensternHorseman->getMobility() <= 100);
    EXPECT_TRUE(ravensternHorseman->getHorseArmor() <= 100);
    EXPECT_TRUE(sarleonHorseman->getHorseSpeed() <= 100);
    EXPECT_TRUE(sarleonHorseman->getArmor() <= 100);
    EXPECT_TRUE(sarleonHorseman->getDamage() <= 100);
    EXPECT_TRUE(sarleonHorseman->getMobility() <= 100);
    EXPECT_TRUE(sarleonHorseman->getHorseArmor() <= 100);
}

TEST_F(unitTest, upSkillCheck) {
    EXPECT_EQ(ravensternHorseman->getSkillLevel(), 0);
    EXPECT_EQ(ravensternInfantryman->getSkillLevel(), 0);
    EXPECT_EQ(ravensternArcher->getSkillLevel(), 0);
    EXPECT_EQ(sarleonHorseman->getSkillLevel(), 0);
    EXPECT_EQ(sarleonInfantryman->getSkillLevel(), 0);
    EXPECT_EQ(sarleonArcher->getSkillLevel(), 0);
    for (int i = 1; i <= 10; ++i) {
        ravensternArcher->upSkillLevel(false);
        ravensternInfantryman->upSkillLevel(false);
        ravensternHorseman->upSkillLevel(false);
        sarleonArcher->upSkillLevel(false);
        sarleonInfantryman->upSkillLevel(false);
        sarleonHorseman->upSkillLevel(false);

        EXPECT_EQ(ravensternHorseman->getSkillLevel(), i);
        EXPECT_EQ(ravensternInfantryman->getSkillLevel(), i);
        EXPECT_EQ(ravensternArcher->getSkillLevel(), i);
        EXPECT_EQ(sarleonHorseman->getSkillLevel(), i);
        EXPECT_EQ(sarleonInfantryman->getSkillLevel(), i);
        EXPECT_EQ(sarleonArcher->getSkillLevel(), i);
    }
}

TEST_F(unitTest, upEquipmentCheck) {
    EXPECT_EQ(ravensternHorseman->getEquipmentLevel(), 0);
    EXPECT_EQ(ravensternInfantryman->getEquipmentLevel(), 0);
    EXPECT_EQ(ravensternArcher->getEquipmentLevel(), 0);
    EXPECT_EQ(sarleonHorseman->getEquipmentLevel(), 0);
    EXPECT_EQ(sarleonInfantryman->getEquipmentLevel(), 0);
    EXPECT_EQ(sarleonArcher->getEquipmentLevel(), 0);
    for (int i = 1; i <= 10; ++i) {
        ravensternArcher->upEquipmentLevel(false);
        ravensternInfantryman->upEquipmentLevel(false);
        ravensternHorseman->upEquipmentLevel(false);
        sarleonArcher->upEquipmentLevel(false);
        sarleonInfantryman->upEquipmentLevel(false);
        sarleonHorseman->upEquipmentLevel(false);

        EXPECT_EQ(ravensternHorseman->getEquipmentLevel(), i);
        EXPECT_EQ(ravensternInfantryman->getEquipmentLevel(), i);
        EXPECT_EQ(ravensternArcher->getEquipmentLevel(), i);
        EXPECT_EQ(sarleonHorseman->getEquipmentLevel(), i);
        EXPECT_EQ(sarleonInfantryman->getEquipmentLevel(), i);
        EXPECT_EQ(sarleonArcher->getEquipmentLevel(), i);
    }
}

TEST_F(unitTest, setGetDeadCheck) {
    EXPECT_FALSE(ravensternHorseman->getDead());
    EXPECT_FALSE(ravensternInfantryman->getDead());
    EXPECT_FALSE(ravensternArcher->getDead());
    EXPECT_FALSE(sarleonHorseman->getDead());
    EXPECT_FALSE(sarleonInfantryman->getDead());
    EXPECT_FALSE(sarleonArcher->getDead());

    EXPECT_NO_THROW(ravensternArcher->setDead(true));
    EXPECT_NO_THROW(ravensternInfantryman->setDead(true));
    EXPECT_NO_THROW(ravensternHorseman->setDead(true));
    EXPECT_NO_THROW(sarleonArcher->setDead(true));
    EXPECT_NO_THROW(sarleonInfantryman->setDead(true));
    EXPECT_NO_THROW(sarleonHorseman->setDead(true));

    EXPECT_TRUE(ravensternHorseman->getDead());
    EXPECT_TRUE(ravensternInfantryman->getDead());
    EXPECT_TRUE(ravensternArcher->getDead());
    EXPECT_TRUE(sarleonHorseman->getDead());
    EXPECT_TRUE(sarleonInfantryman->getDead());
    EXPECT_TRUE(sarleonArcher->getDead());

    EXPECT_NO_THROW(ravensternArcher->setDead(false));
    EXPECT_NO_THROW(ravensternInfantryman->setDead(false));
    EXPECT_NO_THROW(ravensternHorseman->setDead(false));
    EXPECT_NO_THROW(sarleonArcher->setDead(false));
    EXPECT_NO_THROW(sarleonInfantryman->setDead(false));
    EXPECT_NO_THROW(sarleonHorseman->setDead(false));

    EXPECT_FALSE(ravensternHorseman->getDead());
    EXPECT_FALSE(ravensternInfantryman->getDead());
    EXPECT_FALSE(ravensternArcher->getDead());
    EXPECT_FALSE(sarleonHorseman->getDead());
    EXPECT_FALSE(sarleonInfantryman->getDead());
    EXPECT_FALSE(sarleonArcher->getDead());
}