#include <iostream>

int ChangeVal(int* p) {
	*p = 3;

	return 0;
}

int ChangeValRef(int& p) {
	p = 3;

	return 0;
}

int main() {
	/*int number = 5;
	std::cout << number << std::endl;

	ChangeVal(&number);

	std::cout << number << std::endl;

	return 0;*/

	/*int a = 3;
	int& anotherA = a;

	anotherA = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "anotherA : " << anotherA << std::endl;

	return 0;*/

	/*int number = 5;

	std::cout << number << std::endl;
	ChangeValRef(number);
	std::cout << number << std::endl;

	return 0;*/

	/*int x;
	int& y = x;
	int& z = y;

	x = 1;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	y = 2;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	z = 3;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;*/

	int arr[3] = { 1,2,3 };
	int(&ref)[3] = arr;

	ref[0] = 2;
	ref[1] = 3;
	ref[2] = 1;

	std::cout << arr[0] << arr[1] << arr[2] << std::endl;
	return 0;
}