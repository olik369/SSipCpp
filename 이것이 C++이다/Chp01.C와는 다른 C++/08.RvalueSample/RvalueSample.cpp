#include <iostream>
using namespace std;
//r-value�� ���Կ������� �� �ǿ����� �� �����ʿ� ��ġ�� ������

int TestFunc(int nParam) {
	int nResult = nParam * 2;

	return nResult;
}

int main() {
	int nInput = 0;
	cout << "Input number : ";
	cin >> nInput;

	//��� �������� ������� �ӽ� ��ü�� ���� r-value ����
	int&& rdata = nInput + 5;
	cout << rdata << endl;

	//�Լ� ��ȯ���� ������� �ӽ� ��ü�� ���� r-value ����
	int&& result = TestFunc(10);

	//���� ������ �� �ִ�.
	result += 10;
	cout << result << endl;
	
	return 0;
}