
#ifndef Jueguito_COMBAT_H
#define Jueguito_H
#pragma once
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include "Action.h"
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Combat {
private:

    vector<Character*> participants;
    vector<Player*> teamMembers;
    vector<Enemy*> enemies;

    priority_queue<Action> actions; //COLA DE PRIORIDAD PARA ALMACENAR  personajes, jugadores, enemigos y acciones.

    void prepareCombat();
    Character* getTarget(Character* target);
public:
    Combat(vector<Character*> _participants);
    Combat(vector<Player*> _teamMembers, vector<Enemy*> _enemies);
    Combat();
    void addParticipant(Character *participant);
    void doCombat();
    string participantsToString();
};


#endif //RPG_COMBAT_H