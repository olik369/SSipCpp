#include <iostream>
using namespace std;

class Marine {
	int hp;					//마린 체력
	int coord_x, coord_y;	//마린 위치
	int damage;				//공격력
	bool is_dead;

public:
	Marine();				//기본 생성자
	Marine(int x, int y);	//x, y 좌표에 마린 생성

	int Attack();			//데미지를 리턴한다
	void BeAttacked(int damage_earn);	//입는 데미지
	void Move(int x, int y);			//새로운 위치
	
	void ShowStatus();		//상태를 보여줌
};

Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	is_dead = false;
}

Marine::Marine(int x, int y) {
	hp = 50;
	coord_x = x;
	coord_y = y;
	damage = 5;
	is_dead = false;
}

void Marine::Move(int x, int y) {
	coord_x = x;
	coord_y = y;
}

int Marine::Attack() { return damage; }

void Marine::BeAttacked(int damage_earn) {
	hp -= damage_earn;

	if (hp <= 0) {
		is_dead = true;
	}
}

void Marine::ShowStatus() {
	cout << "*** Marine ***" << endl;
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
	cout << " HP : " << hp << endl;
}

int main() {
	Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.ShowStatus();
	marine2.ShowStatus();

	cout << endl << "마린 1이 마린 2를 공격" << endl;
	marine2.BeAttacked(marine1.Attack());

	marine1.ShowStatus();
	marine2.ShowStatus();
}