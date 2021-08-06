#pragma once
#include <iostream>

class Marine {
	static int total_marine_num;
	const static int i = 0;

	int hp;
	int coord_x, coord_y;
	bool is_dead;

	const int default_damage;	//기본 공격력
public:
	Marine();
	Marine(int x, int y);
	Marine(int x, int y, int default_damage);

	int attack();
	void be_attacked(int damage_earn);
	void move(int x, int y);

	void show_status();
	static void show_total_marine() {
		std::cout << "전체 마린 수 : " << total_marine_num << std::endl;
	}

	~Marine() { total_marine_num--; }
};

//생성자 초기화 리스트
Marine::Marine() : hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage)
	: coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false) {
	total_marine_num++;
}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::attack() {
	return default_damage;
}

void Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) { is_dead = true; }
}

void Marine::show_status() {
	std::cout << " *** Marine *** " << std::endl;
	std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << std::endl;
	std::cout << " HP : " << hp << std::endl;
	std::cout << " 현재 총 마린 수 : " << total_marine_num << std::endl;
}

void create_marine() {
	Marine marine3(10, 10, 4);
	Marine::show_total_marine();
}