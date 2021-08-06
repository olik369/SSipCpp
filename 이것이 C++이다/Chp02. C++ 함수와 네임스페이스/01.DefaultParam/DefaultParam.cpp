#include <iostream>

int TestFunc(int nParam = 10) {
	return nParam;
}

int TestFunc2(int nParam1, int nParam2 = 2) {
	return nParam1 * nParam2;
}

int main() {
	//디폴트 매개변수 적용!
	std::cout << TestFunc() << std::endl;

	std::cout << TestFunc(20) << std::endl;

	std::cout << TestFunc2(10) << std::endl;
	std::cout << TestFunc2(10, 5) << std::endl;

	return 0;
}