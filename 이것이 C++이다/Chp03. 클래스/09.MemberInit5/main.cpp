#include <tchar.h>
#include <iostream>
using namespace std;

class CTest
{
public:
	// 생성자
	CTest() {}

	// C++ 11 부터는 멤버변수 선언 시 초기화 이런식으로 가능!(매우 직관적으로~)
	int m_nData1 = 10;
	int m_nData2 = 20;

	void PrintData(void)
	{
		cout << m_nData1 << endl;
		cout << m_nData2 << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	CTest test;
	test.PrintData();

	return 0;
}