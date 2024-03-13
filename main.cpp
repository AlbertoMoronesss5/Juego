#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"


using namespace std;

int main() {
    cout << "WELCOME. Please write a name for your Player: " << endl;
    string playerName;
    cin >> playerName;

    cout << "Write a name for the ENEMY:" << endl;
    string enemyName;
    cin >> enemyName;

    Player *player = new Player(playerName, 10, 3, 2, 3);
    Enemy *enemy = new Enemy(enemyName,8, 4, 1, 4);

    vector<Character*> participants;
    participants.push_back(player);
    participants.push_back(enemy);

    Combat* combat = new Combat(participants);
    combat -> doCombat();

    delete player;
    delete enemy;
    delete combat;

    return 0;
}
//ALBERTO ALEJANDRO MORONES AREVALO 23310119