
#ifndef Jueguito_ENEMY_H
#define Jueguito_ENEMY_H
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Combat/Action.h"
#include <vector>

struct Action;
class Player;

class Enemy: public Character {
public:

    std::vector<Player*> teamMembers;

    Enemy(string, int, int, int, int);

    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Action takeAction(vector<Character> possibleTargets) override;



    Character* getTarget(vector<Player*> teamMembers);

};


#endif