#include <tchar.h>
#include <iostream>
using namespace std;

// ������ �ڵ�
class CMyData
{
	// �⺻ ���� ���� �����ڴ� 'private'�̴�!
	int m_nData;
	// ������ ���� ���������� private���� ������ �� ����!!
	//CMyData() {}

public:
	int GetData(void) { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
};

// ����� �ڵ�
int _tmain(int argc, _TCHAR* argv)
{
	CMyData data;
	// ��� ������ �������� ������ private�� �̻� �Ұ���!
	//data.m_nData = 10;
	data.SetData(10);
	cout << data.GetData() << endl;

	return 0;
}