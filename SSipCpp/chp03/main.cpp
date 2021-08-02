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
	cout << "동물의 이름은? : ";
	cin >> animal->name;
	cout << "동물의 나이는? : ";
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
	cout << "---- " << animal->name << "의 상태 ----" << endl;

	cout << "나 이 : " << animal->age << endl;
	cout << "건 강 : " << animal->health << endl;
	cout << "배부름 : " << animal->food << endl;
	cout << "청 결 : " << animal->clean << endl;
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
		cout << "1. 동물 추가하기" << endl;
		cout << "2. 놀기" << endl;
		cout << "3. 상태 보기" << endl;

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
			cout << "누구와 놀까? : ";
			cin >> play_with;

			if (play_with < animal_num) { Play(list[play_with]); }
			break;
		case 3:
			cout << "누구 보고 싶어? : ";
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