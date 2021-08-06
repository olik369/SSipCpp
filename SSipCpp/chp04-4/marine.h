#pragma
#include <iostream>

class Marine {
	int hp;
	int coord_x, coord_y;
	int damage;
	bool is_dead;

public:
	Marine();
	Marine(int x, int y);
	Marine(int x, int y, int default_damage);

	int attack();
	void be_attacked(int damage_earn);
	void move(int x, int y);

	void show_status();
};

//생성자 초기화 리스트
Marine::Marine() : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false) {}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), damage(5), is_dead(false) {}

Marine::Marine(int x, int y, int default_damage)
	: coord_x(x), coord_y(y), hp(50), damage(default_damage), is_dead(false) {}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::attack() {
	return damage;
}

void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) { is_dead = true; }
}

void Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
}