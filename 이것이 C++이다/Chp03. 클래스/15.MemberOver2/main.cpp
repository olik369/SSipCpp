#include <iostream>
using namespace std;

class CMyData {
public:
	CMyData() : m_nData(0) {}

	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	//실수로 double형 실인수가 넘어오는 경우를 차단한다.
	void SetData(double dParam) = delete;

private:
	int m_nData;
};

int main() {
	CMyData a;

	a.SetData(10);
	cout << a.GetData() << endl;

	/*CMyData b;
	b.SetData(5.5);
	cout << b.GetData() << endl;*/

	return 0;
}