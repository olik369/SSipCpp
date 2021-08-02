#include <iostream>
using namespace std;

struct Animal {
	char name[30];
	int age;
	int health;
	int food;
	int clean;
};

void CreateAnimal(Animal* animal) {
	cout << "������ �̸���? : ";
	cin >> animal->name;
	cout << "������ ���̴�? : ";
	cin >> animal->age;

	animal->health = 100;
	animal->food = 100;
	animal->clean = 100;

}

void Play(Animal* animal) {
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;
}

void OneDayPass(Animal* animal) {
	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

void ShowStat(Animal* animal) {
	cout << "---- " << animal->name << "�� ���� ----" << endl;

	cout << "�� �� : " << animal->age << endl;
	cout << "�� �� : " << animal->health << endl;
	cout << "��θ� : " << animal->food << endl;
	cout << "û �� : " << animal->clean << endl;
}

int main() {
	/*int* p = new int;
	*p = 10;

	std::cout << *p << std::endl;

	delete p;
	return 0;*/

	/*int arr_size;
	std::cout << "array size : ";
	std::cin >> arr_size;
	int* list = new int[arr_size];

	for (int i = 0; i < arr_size; i++) {
		std::cin >> list[i];
	}

	for (int i = 0; i < arr_size; i++) {
		std::cout << i << "th element of list : " << list[i] << std::endl;
	}

	delete[] list;
	return 0;*/

	Animal* list[10];
	int animal_num = 0;

	while (true)
	{
		cout << "1. ���� �߰��ϱ�" << endl;
		cout << "2. ���" << endl;
		cout << "3. ���� ����" << endl;

		int input;
		cin >> input;

		switch (input)
		{
			int play_with;
		case 1:
			list[animal_num] = new Animal;
			CreateAnimal(list[animal_num]);

			animal_num++;
			break;
		case 2:
			cout << "������ ���? : ";
			cin >> play_with;

			if (play_with < animal_num) { Play(list[play_with]); }
			break;
		case 3:
			cout << "���� ���� �;�? : ";
			cin >> play_with;
			if (play_with < animal_num) { ShowStat(list[play_with]); }
			break;
		default:
			break;
		}

		for (int i = 0; i != animal_num; i++) {
			OneDayPass(list[i]);
		}
	}

	for (int i = 0; i != animal_num; i++) {
		delete list[i];
	}

	return 0;
}