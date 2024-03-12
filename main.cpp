#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"
#include <vector>

using namespace std;

int main() {
    cout << "WELCOME. Please write a name for your Player: " << endl;
    string playerName;
    cin >> playerName;

    cout << "Write a name for the ENEMY:" << endl;
    string enemyName;
    cin >> enemyName;

    Player *player = new Player(playerName, 10, 2, 3, 3);
    Enemy *enemy = new Enemy(enemyName,10, 4, 3, 4);

    vector<Character*> participants;
    participants.push_back(player);
    participants.push_back(enemy);

    Combat* combat = new Combat(participants);

    int choice;
    do {
        cout << "1. Attack\n";
        cout << "2. Exit\n";
        cout << "Chose Someone Option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                combat->doCombat();
                break;
            case 2:
                cout << "¡GOODBYE!\n";
                break;
            default:
                cout << "PLEASE. Write a correct option\n";
        }
    } while (choice != 2);

    delete player;
    delete enemy;
    delete combat;

    return 0;
}
//ALBERTO ALEJANDRO MORONES AREVALO 23310119