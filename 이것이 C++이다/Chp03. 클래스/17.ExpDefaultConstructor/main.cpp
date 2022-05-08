#include <tchar.h>
#include <iostream>
using namespace std;

class CTest
{
public:
	// 디폴트 생성자 선언
	CTest(void) = default;
	// 커스텀 생성자를 생성 시 디폴트 생성자를 따로 만들어야 되는데 이때 구현을 클래스 내부에서 하면 문제가 생기는 경우가 있음
	// 그래서 디폴트 예약어가 존재하는 것임(주로 템플릿 프로그래밍을 하거나 인터페이스화 시킨 클래스의 경우 문제가 많음)
	
	// C++에서 고질적인 문제중 하나인 필요없는 함수를 지우는 방법이 없었다는 것을 해결해주는 예약어임
	//CTest(void) = delete;
	int m_nData = 5;
};

// 클래스 외부에서 디폴트 생성자 정의
//CTest::CTest(void) {}

int _tmain(int argc, _TCHAR* argv[])
{
	CTest a;
	cout << a.m_nData << endl;

	return 0;
}