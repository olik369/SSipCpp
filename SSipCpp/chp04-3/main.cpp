#include <iostream>
using namespace std;

class Marine {
	int hp;					//���� ü��
	int coord_x, coord_y;	//���� ��ġ
	int damage;				//���ݷ�
	bool is_dead;

public:
	Marine();				//�⺻ ������
	Marine(int x, int y);	//x, y ��ǥ�� ���� ����

	int Attack();			//�������� �����Ѵ�
	void BeAttacked(int damage_earn);	//�Դ� ������
	void Move(int x, int y);			//���ο� ��ġ
	
	void ShowStatus();		//���¸� ������
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

	cout << endl << "���� 1�� ���� 2�� ����" << endl;
	marine2.BeAttacked(marine1.Attack());

	marine1.ShowStatus();
	marine2.ShowStatus();
}