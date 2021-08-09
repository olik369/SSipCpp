#include <iostream>
using namespace std;

class CTest {
public:
	CTest(int nParam) : m_nData(nParam) {}
	~CTest() {}
	
	int GetData() const {
		return m_nData;
	}

	int SetData(int nParam) { m_nData = nParam; }
private:
	int m_nData = 0;
};

int main() {
	CTest a(10);
	cout << a.GetData() << endl;

	return 0;
}