#include <tchar.h>
#include <iostream>
using namespace std;

// �������� �ڵ�
class CTest
{
public:
	//CTest Ŭ������ '������ �Լ�' ���� �� ����
	CTest()
	{
		// �ν��Ͻ��� �����Ǹ� ��� �����͸� '�ڵ�'���� �ʱ�ȭ�Ѵ�.
		m_nData = 10;
	}

	int m_nData;

	// ��� �Լ� ����. ���Ǵ� �и��ߴ�!
	void PrintData(void);
};

// �ܺο� �и��� ��� �Լ� ����
void CTest::PrintData(void)
{
	cout << m_nData << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CTest test;
	test.PrintData();

	return 0;
}