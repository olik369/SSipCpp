#include <tchar.h>
#include <iostream>
using namespace std;

class CTest
{
	int m_nData;

public:
	// 생성자의 매개변수로 전달된 값으로 멤버 변수를 초기화한다.
	CTest(int nParam) : m_nData(nParam)
	{
		cout << "CTest::CTest()" << endl;
	}

	~CTest()
	{
		// 생성할 때 매개변수로 받은 값을 출력한다.
		cout << "~CTest::CTest() " << m_nData << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Begin" << endl;
	CTest a(1);
	cout << "Before b" << endl;
	CTest b(2);
	cout << "End" << endl;

	// 디폴트 생성자외의 생성자를 선언할 시 디폴트값으로 인스턴스 생성 불가!!
	//CTest c;

	return 0;
}