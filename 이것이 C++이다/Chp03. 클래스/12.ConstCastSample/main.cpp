#include <iostream>
using namespace std;

void TestFunc(const int& nParam) {
	//����� ���������� �Ϲ� ������ ����ȯ�ߴ�.
	int& nNewParam = const_cast<int&>(nParam);

	//���� l-value�� �� �� �ִ�.
	nNewParam = 20;
}

int main() {
	int nData = 10;

	TestFunc(nData);

	cout << nData << endl;

	return 0;
}