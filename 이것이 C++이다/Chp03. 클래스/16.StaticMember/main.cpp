#include <iostream>
using namespace std;

class CTest {
public:
	CTest(int nParam) :m_nData(nParam) { m_nCount++; }
	int GetData() { return m_nData; }
	void ResetCount() { m_nCount = 0; }

	static int GetCount() {
		return m_nCount;
	}
private:
	int m_nData;

	static int m_nCount;
};

// CTest 클래스의 정적 멤버 변수 정의
int CTest::m_nCount = 0;

int main() {
	CTest a(5), b(10);

	// 정적 멤버에 접근
	cout << a.GetCount() << endl;
	b.ResetCount();

	//정적 멤버에 접근, 인스턴스 없이도 접근 가능!
	cout << CTest::GetCount() << endl;

	return 0;
}