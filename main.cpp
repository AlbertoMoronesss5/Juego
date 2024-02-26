#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "../Character/Character.h"

using namespace std;

int main() {
    Player *player1 = nullptr;
    Enemy *enemy1 = nullptr;

    int opcion;
    cout << "Welcome to my game\n";
    cout << "1. Personalize names\n";
    cout << "2. Exit ";
    cout << "\n";
    cin >> opcion;

    switch (opcion) {
        case 1: {
            string playerName, enemyName;
            cout << "Enter name for Player: ";
            cin >> playerName;
            cout << "Enter name for Enemy: ";
            cin >> enemyName;
            player1 = new Player(playerName, 20);
            enemy1 = new Enemy(enemyName, 20);
            break;
        }
        case 2: {
            exit(0);
        }
        default:
            cerr << "No option \n";
            return 1;
    }

    int i = 0;
    do {
        cout << "ROUND..... " << ++i << "\n";
        player1->getAttack(enemy1);
        if (!enemy1->alive()) {
            cout << player1->getName() << " WON the fight" << endl;
            break;
        }

        cout << "\n";

        enemy1->getAttack(player1);
        if (!player1->alive()) {
            cout << enemy1->getName() << " WON the fight" << endl;
            break;
        }

        cout << "\n";
    } while (player1->alive() && enemy1->alive());

    delete player1;
    delete enemy1;

    return 0;
}
