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

    Player *player = new Player(playerName, 20, 2, 3, 1);
    Enemy *enemy = new Enemy(enemyName, 20, 5, 3, 7);
    Enemy *enemy2 = new Enemy("Orc", 30, 8, 5, 2);

    vector<Character*> participants;
    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat* combat = new Combat(participants);

    int choice;
    do {
        cout << "1. Atacar\n";
        cout << "2. Salir\n";
        cout << "Elige una opción: ";
        cin >> choice;

        switch (choice) {
            case 1:
                combat->doCombat();
                break;
            case 2:
                cout << "¡Hasta luego!\n";
                break;
            default:
                cout << "Opción no válida\n";
        }
    } while (choice != 2);

    delete player;
    delete enemy;
    delete enemy2;
    delete combat;

    return 0;
}
