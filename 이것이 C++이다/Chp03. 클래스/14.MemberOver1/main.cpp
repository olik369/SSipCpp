//#include <iostream>
//using namespace std;
//
//class CMyData {
//public:
//	CMyData() : m_nData(0) {}
//
//	int GetData() { return m_nData; }
//	void SetData(int nParam) { m_nData = nParam; }
//
//	void SetData(double dParam) { m_nData = 0; }
//private:
//	int m_nData;
//};
//
//int main() {
//	CMyData a, b;
//
//	a.SetData(10);
//	b.SetData(5.5);
//
//	cout << a.GetData() << endl;
//	cout << b.GetData() << endl;
//
//	return 0;
//}

#include <iostream>
using namespace std;

class CRefTest {
public:
	CRefTest(int& rParam) : m_nData(rParam) {}

	int GetData() { return m_nData; }
private:
	int& m_nData;
};

int main() {

}