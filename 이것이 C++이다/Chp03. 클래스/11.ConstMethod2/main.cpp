#include <iostream>
using namespace std;

class CTest {
public:
	CTest(int nParam) : m_nData(nParam) {}
	~CTest() {}

	//mutable로 선언한 멤버변수는 상수형 메서드에서도 값변경 가능!
	int GetData() const {
		m_nData = 20;
		return m_nData;
	}

	int SetData(int nParam) { m_nData = nParam; }
private:
	mutable int m_nData = 0;
};

int main() {
	CTest a(10);
	cout << a.GetData() << endl;

	return 0;
}