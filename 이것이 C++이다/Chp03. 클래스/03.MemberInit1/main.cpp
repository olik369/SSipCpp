#include <iostream>
using namespace std;

class CTest {
public:
	//CTest Ŭ������ '������ �Լ�' ���� �� ����
	CTest() {
		//�ν��Ͻ��� �����Ǹ� ��� �����͸� '�ڵ�����' �ʱ�ȭ�Ѵ�.
		m_nData = 10;
	}

	//��� ������ ����
	int m_nData;

	//��� �Լ� ���� �� ����
	void PrintData() {
		//��� �����Ϳ� �����ϰ� ���� ����Ѵ�.
		cout << m_nData << endl;
	}
};

//����� �ڵ�
int main() {
	CTest t;
	t.PrintData();

	return 0;
}