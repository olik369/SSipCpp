#include <tchar.h>
#include <iostream>
using namespace std;

// 제작자 코드
class CMyData
{
	// 기본 접근 제어 지시자는 'private'이다!
	int m_nData;
	// 생성자 선언도 마찬가지로 private으로 선언할 수 있음!!
	//CMyData() {}

public:
	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
};

// 사용자 코드
int _tmain(int argc, _TCHAR* argv)
{
	CMyData data;
	// 멤버 변수에 직접적인 접근은 private인 이상 불가능!
	//data.m_nData = 10;
	data.SetData(10);
	cout << data.GetData() << endl;

	return 0;
}