#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include "photoncannon.h"
#include "Question1.h"
using namespace std;

class Marine {
	int hp;					//마린 체력
	int coord_x, coord_y;	//마린 위치
	int damage;				//공격력
	char* name;
	bool is_dead;

public:
	Marine();				//기본 생성자
	Marine(int x, int y, const char* marine_name);
	Marine(int x, int y);	//x, y 좌표에 마린 생성
	~Marine();

	int Attack();			//데미지를 리턴한다
	void BeAttacked(int damage_earn);	//입는 데미지
	void Move(int x, int y);			//새로운 위치
	
	void ShowStatus();		//상태를 보여줌
};

Marine::Marine() {
	hp = 50;
	coord_x = coord_y = 0;
	damage = 5;
	name = NULL;
	is_dead = false;
}

Marine::Marine(int x, int y, const char* marine_name) {
	hp = 50;
	coord_x = x;
	coord_y = y;
	damage = 5;
	is_dead = false;

	name = new char[strlen(marine_name) + 1];
	strcpy(name, marine_name);
}

Marine::Marine(int x, int y) {
	hp = 50;
	coord_x = x;
	coord_y = y;
	damage = 5;
	is_dead = false;
	name = NULL;
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
	cout << "*** Marine : " << name << " ***" << endl;
	cout << " Location : ( " << coord_x << " , " << coord_y << " ) " << endl;
	cout << " HP : " << hp << endl;
}

/*
//배열 형태의 메모리 할당 사용법
타입 *변수명 = new 타입[크기]; //배열 형태 메모리 할당
delete[] 변수명 //배열 형태 메모리 할당해제
*/

//소멸자
Marine::~Marine() {
	cout << name << " 의 소멸자 호출 ! " << endl;
	if (name != NULL) {
		delete[] name;
	}
}

class Test {
	char c;

public:
	Test(char _c) {
		c = _c;
		cout << "생성자 호출 " << c << endl;
	}
	~Test() {
		cout << "소멸자 호출 " << c << endl;
	}
};

void SimpleFunction() { Test b('b'); }

int main() {
	/*Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.ShowStatus();
	marine2.ShowStatus();

	cout << endl << "마린 1이 마린 2를 공격" << endl;
	marine2.BeAttacked(marine1.Attack());

	marine1.ShowStatus();
	marine2.ShowStatus();*/

	/*
	Marine* marines[100];

	marines[0] = new Marine(2, 3, "Marine 1");
	marines[1] = new Marine(3, 5, "Marine 2");

	marines[0]->ShowStatus();
	marines[1]->ShowStatus();

	cout << endl << "마린 1이 마린 2를 공격! " << endl;

	marines[1]->BeAttacked(marines[0]->Attack());

	marines[0]->ShowStatus();
	marines[1]->ShowStatus();

	delete marines[0];
	delete marines[1];
	*/

	/*Test a('a');
	SimpleFunction();*/

	/*PhotonCannon pc1(3, 3, "Cannon");
	PhotonCannon pc2 = pc1;

	pc1.ShowStatus();
	pc2.ShowStatus();*/

	String str1("aaa");
	String str2("bbb");

	cout << str1.str << endl;


	return 0;
}