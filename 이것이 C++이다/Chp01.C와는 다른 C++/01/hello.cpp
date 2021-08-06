#include <iostream>

int main(int argc, char* argv[]) {
	int a(10);
	auto b(a);

	std::cout << b << std::endl;

	return 0;
}