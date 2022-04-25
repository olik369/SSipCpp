#include <tchar.h>
#include <iostream>
using namespace std;

// 제작자의 코드
class CTest
{
public:
	//CTest 클래스의 '생성자 함수' 선언 및 정의
	CTest()
	{
		// 인스턴스가 생성되면 멤버 데이터를 '자동'으로 초기화한다.
		m_nData = 10;
	}

	int m_nData;

	// 멤버 함수 선언. 정의는 분리했다!
	void PrintData(void);
};

// 외부에 분리된 멤버 함수 정의
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