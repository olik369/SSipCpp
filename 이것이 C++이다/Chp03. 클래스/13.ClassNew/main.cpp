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

	// new 연산자를 이용해 동적으로 객체를 생성한다!
	CTest* pData = new CTest;
	cout << "Test" << endl;

	// delete 연산자를 이용해 객체를 삭제한다.
	delete pData;
	cout << "End" << endl;

	// 배열로 new연산을 수행할 수 있다.
	CTest* pArrData = new CTest[3];

	// 반드시 배열로 삭제해야 한다!, 이것을 실수하면 메모리 릭(leak) 버그를 만듬
	delete [] pArrData;

	return 0;
}