#include <tchar.h>
#include <iostream>
using namespace std;

// ������ �ڵ�
class CTest
{
public:
	// CTest Ŭ������ '������ �Լ�' ���� �� ����
	CTest()
	{
		// �ν��Ͻ��� �����Ǹ� ��� �����͸� '�ڵ�����' �ʱ�ȭ�Ѵ�.
		cout << "CTest() : ������ �Լ�" << endl;
		m_nData = 10;
	}

	// ��� ������ ����
	int m_nData;

	// ��� �Լ� ���� �� ����
	void PrintData(void)
	{
		// ��� �����Ϳ� �����ϰ� ���� ����Ѵ�.
		cout << m_nData << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "_tmain() �Լ� ����" << endl;

	CTest t;
	t.PrintData();

	cout << "_tmain() �Լ� ��" << endl;

	return 0;
}