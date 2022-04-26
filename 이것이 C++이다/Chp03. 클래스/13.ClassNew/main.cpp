#include <tchar.h>
#include <iostream>
using namespace std;

class CTest
{
	int m_nData;

public:
	CTest()
	{
		cout << "CTest::CTest()" << endl;
	}

	~CTest()
	{
		cout << "~CTest::CTest()" << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Begin" << endl;

	// new �����ڸ� �̿��� �������� ��ü�� �����Ѵ�!
	CTest* pData = new CTest;
	cout << "Test" << endl;

	// delete �����ڸ� �̿��� ��ü�� �����Ѵ�.
	delete pData;
	cout << "End" << endl;

	// �迭�� new������ ������ �� �ִ�.
	CTest* pArrData = new CTest[3];

	// �ݵ�� �迭�� �����ؾ� �Ѵ�!, �̰��� �Ǽ��ϸ� �޸� ��(leak) ���׸� ����
	delete [] pArrData;

	return 0;
}