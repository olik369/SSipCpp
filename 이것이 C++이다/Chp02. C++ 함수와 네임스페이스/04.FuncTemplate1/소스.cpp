#include <iostream>
using namespace std;

template <typename T>
T TestFunc(T a) {
	cout << "매개변수 a: " << a << endl;

	return a;
}

template <typename T>
T Add(T a, T b) {
	return a + b;
}

int main() {
	/*cout << "int\t" << TestFunc(3) << endl;
	cout << "double\t" << TestFunc(3.3) << endl;
	cout << "char\t" << TestFunc('A') << endl;
	cout << "char*\t" << TestFunc("TestString") << endl;*/

	cout << Add(3, 4) << endl;
	cout << Add(3.3, 4.4) << endl;

	return 0;
}