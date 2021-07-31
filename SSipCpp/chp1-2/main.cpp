#include <iostream>

namespace {
	int onlyInThisFile() { return 0; }

	int only_int_this_file = 0;
}

int main() {
	std::cout << "Hello World!!" << std::endl;
	onlyInThisFile();
	only_int_this_file = 3;

	std::cout << "hi" << std::endl
		<< "my name is "
		<< "Psi" << std::endl;
	return 0;
}