#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"


using namespace std;

int main() {
    cout << "WELCOME. Please write a name for your PLAYER: " << endl;
    string playerName;
    cin >> playerName;

    cout << "Write a name for the ENEMY:" << endl;
    string enemyName;
    cin >> enemyName;

    cout<<"Write an arm for your PLAYER: "<< endl;
    string playerArm;
    cin>>  playerArm;

    cout<<"Write an arm for your ENEMY: "<< endl;
    string EnemyArm;
    cin>>  EnemyArm;


    Player *player = new Player(playerName, 35, 7, 2, 10,EnemyArm);
    Enemy *enemy = new Enemy(enemyName,20, 5, 2, 7,playerArm);

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