

#ifndef Jueguito_CHARACTER_H
#define Jueguito_CHARACTER_H
#include<string>
#include "../Combat/Action.h"
#include <vector>

using namespace std;

class Character {
protected:
    string name;
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool fleed;
    string arm;

public:
    Character(string, int, int, int, int, bool, string);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;


    void setName(string);
    string getName();
    void setHealth(int);
    int getHealth();
    void setAttack(int);
    int getAttack();
    void setDefense(int);
    int getDefense();
    void setSpeed(int);
    int getSpeed();
    string toString();
    bool getIsPlayer();
    bool hasFleed();
    void setArm(string);
    string getArm();
};


#endif