#include <iostream>

/*
int main() {
	int arr[10];
	int* parr = arr;

	int i;
	int* pi = &i;

	for (i = 0; i < 10; i++) {
		std::cout << i << std::endl;
	}

	int sum = 0;

	for (i = 0; i <= 10; i++) {
		sum += i;
	}

	std::cout << "���� : " << sum << std::endl;

	int userInput;
	int luckyNumber = 3;

	std::cout << "�� ��� ���� ���߾� ������~" << std::endl;
	while (true) {
		std::cout << "�Է� : ";
		std::cin >> userInput;

		if (luckyNumber == userInput) {
			std::cout << "���߼̽��ϴ�~~" << std::endl;
			break;
		}
		else {
			std::cout << "�ٽ� �����غ�����~" << std::endl;
		}
		
	}
	return 0;
}
*/

using std::cout;
using std::cin;
using std::endl;

int main() {
	int userInput;
	cout << "���� ������ ǥ�����ݴϴ�." << endl;
	cout << "1. �̸�" << endl;
	cout << "2. ����" << endl;
	cout << "3. ����" << endl;
	cin >> userInput;

	switch (userInput)
	{
	case 1:
		cout << "��ȣ!" << endl;
		break;
	case 2:
		cout << "27©" << endl;
		break;
	case 3:
		cout << "����" << endl;
		break;

	default:
		cout << "�ñ��Ѱ� ����? �Ф�" << endl;
		break;
	}

	return 0;

}