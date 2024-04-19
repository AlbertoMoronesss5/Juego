
#include <cstring> //agregar para mover cadenas

#ifndef Jueguito_CHARACTER_H
#define Jueguito_CHARACTER_H
#include<string>
#include "../Combat/Action.h"
#include <vector>
#include <cstring>

using namespace std;

//atributos
class Character {
protected:
    char name[30];
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool fleed;
    char arm[20];

public:
    Character(char[30], int, int, int, int, bool, char[20]);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;


    void setName(char[30]);
    char* getName();
    void setHealth(int);
    int getHealth();
    void setAttack(int);
    int getAttack();
    void setDefense(int);
    int getDefense();
    void setSpeed(int);
    int getSpeed();
    char toString(); //que diablos hace? MUESTRA TODOS LOS DATOS?
    bool getIsPlayer();
    bool hasFleed();
    void setArm(char[20]);
    char* getArm();
};

#endif