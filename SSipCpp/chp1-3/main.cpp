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

	std::cout << "합은 : " << sum << std::endl;

	int userInput;
	int luckyNumber = 3;

	std::cout << "내 비밀 수를 맞추어 보세요~" << std::endl;
	while (true) {
		std::cout << "입력 : ";
		std::cin >> userInput;

		if (luckyNumber == userInput) {
			std::cout << "맞추셨습니다~~" << std::endl;
			break;
		}
		else {
			std::cout << "다시 생각해보세요~" << std::endl;
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
	cout << "저의 정보를 표시해줍니다." << endl;
	cout << "1. 이름" << endl;
	cout << "2. 나이" << endl;
	cout << "3. 성별" << endl;
	cin >> userInput;

	switch (userInput)
	{
	case 1:
		cout << "동호!" << endl;
		break;
	case 2:
		cout << "27짤" << endl;
		break;
	case 3:
		cout << "남자" << endl;
		break;

	default:
		cout << "궁금한게 없네? ㅠㅠ" << endl;
		break;
	}

	return 0;

}