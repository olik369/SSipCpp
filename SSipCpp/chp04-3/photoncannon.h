#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class PhotonCannon {
	int hp, shield;
	int coord_x, coord_y;
	int damage;

	char* name;

public:
	PhotonCannon(int x, int y);
	PhotonCannon(int x, int y, const char* cannon_name);
	PhotonCannon(const PhotonCannon& pc);
	~PhotonCannon();

	void ShowStatus();
};

PhotonCannon::PhotonCannon(int x, int y, const char* cannon_name) {
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;
	name = new char[strlen(cannon_name) + 1];
	strcpy(name, cannon_name);
}

PhotonCannon::PhotonCannon(int x, int y) {
	cout << "생성자 호출 !" << endl;
	hp = shield = 100;
	coord_x = x;
	coord_y = y;
	damage = 20;

	name = NULL;
}

PhotonCannon::PhotonCannon(const PhotonCannon& pc) {
	cout << "복사 생성자 호출! " << endl;
	hp = pc.hp;
	shield = pc.shield;
	coord_x = pc.coord_x;
	coord_y = pc.coord_y;
	damage = pc.damage;

	name = new char[strlen(pc.name) + 1];
	strcpy(name, pc.name);
}

PhotonCannon::~PhotonCannon() {
	if (name) { delete[] name; }
}

void PhotonCannon::ShowStatus() {
	cout << "Photon Cannon : " << name << endl;
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
	cout << " HP : " << hp << endl;
}