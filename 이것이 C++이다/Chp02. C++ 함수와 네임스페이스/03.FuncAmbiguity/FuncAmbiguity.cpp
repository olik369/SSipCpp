#include <iostream>
using namespace std;

void TestFunc(int a) {
	cout << "TestFunc(int)" << endl;
}

void TestFunc(int a, int b = 10) {
	cout << "TestFunc(int, int)" << endl;
}

int main() {
	//TestFunc(int a)�� ȣ���� ����� ����!!
	//TestFunc(5);

	return 0;
}