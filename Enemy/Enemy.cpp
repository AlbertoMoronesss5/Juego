#include "Enemy.h"
#include <iostream>
#include <climits> // Agregamos la inclusión para INT_MAX

using namespace std;

// TODO: Check the circular dependency
int getRolledAttack(int attack) {
    int lowerLimit = static_cast<int>(attack * 0.80); // Usamos static_cast para la conversión
    return (rand() % (attack - lowerLimit)) + lowerLimit;
}

Enemy::Enemy(string name, int health, int attack, int defense, int speed) : Character(name, health, attack, defense, speed, false) {
}

void Enemy::doAttack(Character *target) {
    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Enemy::takeDamage(int damage) {
    setHealth(getHealth() - damage);
    if (getHealth() <= 0) {
        cout << getName() << " has died" << endl;
    } else {
        cout << getName() << " has taken " << damage << " damage" << endl;
    }
}

Character* Enemy::getTarget(const vector<Player*>& teamMembers) {
    // Obtiene el miembro del equipo con menos vida
    int targetIndex = 0;
    int lowestHealth = INT_MAX;
    for (int i = 0; i < teamMembers.size(); i++) {
        if (teamMembers[i]->getHealth() < lowestHealth) {
            lowestHealth = teamMembers[i]->getHealth();
            targetIndex = i;
        }
    }

    return teamMembers[targetIndex];
}

Action Enemy::takeAction(vector<Player*>& players) {
    Action myAction;
    myAction.speed = getSpeed();
    Character* target = getTarget(players);
    myAction.action = [this, target]() {
        doAttack(target);
    };

    return myAction;
}

Action Enemy::takeAction(vector<shared_ptr<Character>>& possibleTargets) {
int option = 0;
cout << "Choose an action" << endl;
cout << "1. Attack" << endl;

cin >> option;
Character* target = nullptr;

Action myAction;

myAction.speed = getSpeed();

switch (option) {
case 1:
target = getTarget(possibleTargets);
myAction.action = [this, target]() {
    doAttack(target);
};
break;
default:
cout << "Invalid option" << endl;
break;
}

return myAction;
}

Action Player::takeAction(vector<Enemy*>& enemies) {
    int option = 0;
    cout << "Choose an action" << endl;
    cout << "1. Attack" << endl;
    //    cout<<"2. Flee"<<endl;
    cin >> option;
    Character* target = nullptr;

    Action myAction;

    myAction.speed = this->getSpeed();

    switch (option) {
        case 1:
            target = getTarget(enemies);
            myAction.action = [this, target]() {
                doAttack(target);
            };
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }

    return myAction;
}
