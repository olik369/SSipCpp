#pragma once
#include <iostream>
using namespace std;

class Marine {
	static int total_marine_num;	//static 멤버 변수의 사용
	const static int i = 0;

	int hp;					//마린 체력
	int coord_x, coord_y;	//마린 위치
	//int damage;				//공격력
	bool is_dead;

	const int default_damage;	//기본 공격력
public:
	Marine();				//기본 생성자
	Marine(int x, int y);	//x,y 좌표에 마린 생성
	Marine(int x, int y, int default_damage);

	int attack() const;						//데미지를 리턴한다
	Marine& be_attacked(int damage_earn);	//입는 데미지
	void move(int x, int y);			//새로운 위치

	void show_status();					//상태를 보여준다
	static void show_total_marine();
	~Marine() { total_marine_num--; }
};
int Marine::total_marine_num = 0;
void Marine::show_total_marine() {
	cout << "전체 마린 수 : " << total_marine_num << endl;
}

Marine::Marine() :hp(50), coord_x(0), coord_y(0), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y) : coord_x(x), coord_y(y), hp(50), default_damage(5), is_dead(false) {
	total_marine_num++;
}

Marine::Marine(int x, int y, int default_damage) : 
	coord_x(x), coord_y(y), hp(50), default_damage(default_damage), is_dead(false) {
	total_marine_num++;
}

void Marine::move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::attack() const { return default_damage; }	//C#의 readonly와 비슷한 역할을 하게 됨
Marine& Marine::be_attacked(int damage_earn) {
	hp -= damage_earn;
	if (hp <= 0) is_dead = true;

	return *this;
}
void Marine::show_status() {
	cout << "*** Marine ***" << endl;
	cout << "Location : ( " << coord_x<<" , " << coord_y << " ) "<<endl;
	cout << "HP : " << hp << endl;
	cout << "현재 총 마린 수 : " << total_marine_num << endl;
}