#include <iostream>
using namespace std;

class CMyData {
public:
	CMyData() : m_nData(0) {}

	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }

	//�Ǽ��� double�� ���μ��� �Ѿ���� ��츦 �����Ѵ�.
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