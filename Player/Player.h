
#ifndef Jueguito_PLAYER_H
#define Jueguito_PLAYER_H

#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
#include "../Combat/Action.h"
#include <vector>

struct Action;
class Enemy;

class Player: public Character {
    //atributos "personales" de PLAYER
protected:
    int experience;
    int level;
    //Constructor
public:
    Player(char _name[30], int _health, int _attack, int _defense, int _speed, char _arm[20]);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;

    Character* getTarget(vector<Enemy*> enemies);


    void flee(vector<Enemy*> enemies);
    void emote();
    void levelUp();
    void gainExperience(int);
    Action takeAction(vector<Enemy*> enemies);

};



#endif