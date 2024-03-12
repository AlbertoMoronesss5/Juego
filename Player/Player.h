
#ifndef Jueguito_PLAYER_H
#define Jueguito_PLAYER_H

#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
#include "../Combat/Action.h"
#include <vector>

struct Action;
class Enemy;

class Player: public Character {
protected:
    int experience;
    int level;
public:
    Player(string _name, int _health, int _attack, int _defense, int _speed);


    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Action takeAction(vector<Character> possibleTargets) override;

    Character* getTarget(vector<Enemy*> enemies);
    Action takeAction(vector<Enemy*> enemies);


    bool flee(vector<Enemy*> enemies);
    void emote();
    void levelUp();
    void gainExperience(int);



};


#endif