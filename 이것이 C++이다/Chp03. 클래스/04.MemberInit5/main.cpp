#include <iostream>
using namespace std;

class CTest {
public:
	CTest() {}
	
	int m_nData1 = 10;
	int m_nData2 = 20;

	void PrintData() {
		cout << m_nData1 << endl;
		cout << m_nData2 << endl;
	}
};

int main() {
	CTest t;
	t.PrintData();

	return 0;
}