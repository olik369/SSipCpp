#include <iostream>
using namespace std;

//�Ű������� int�� ���� ���������̴�.
void TestFunc(int& rParam) {
	//�� ȣ���� �Լ����� ������ ���� �����ߴ�.
	rParam = 100;
}

int main() {
	/*
	int nData = 10;

	//nData ������ ���� ������ ����
	int& ref = nData;

	//�������� ���� �����ϸ� ������ ����
	ref = 20;
	cout << nData << endl;

	//�����͸� ���� �Ͱ� �����
	int* pnData = &nData;
	*pnData = 30;
	cout << nData << endl;

	return 0;
	*/

	int nData = 0;

	//������ ���� �μ� ����
	TestFunc(nData);
	cout << nData << endl;

	return 0;
}