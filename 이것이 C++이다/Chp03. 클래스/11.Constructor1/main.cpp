#include <tchar.h>
#include <iostream>
using namespace std;

class CTest
{
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

class CTest2
{
public:
	CTest2()
	{
		cout << "CTest2::CTest2()" << endl;
	}

	~CTest2()
	{
		cout << "~CTest2::CTest2()" << endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Begin" << endl;
	CTest a;
	cout << "Before b" << endl;
	CTest2 b;
	cout << "End" << endl;

	return 0;
}
