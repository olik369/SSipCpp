#include <tchar.h>
#include <iostream>
using namespace std;

class CTest
{
public:
	// ����Ʈ ������ ����
	CTest(void) = default;
	// Ŀ���� �����ڸ� ���� �� ����Ʈ �����ڸ� ���� ������ �Ǵµ� �̶� ������ Ŭ���� ���ο��� �ϸ� ������ ����� ��찡 ����
	// �׷��� ����Ʈ ���� �����ϴ� ����(�ַ� ���ø� ���α׷����� �ϰų� �������̽�ȭ ��Ų Ŭ������ ��� ������ ����)
	
	// C++���� �������� ������ �ϳ��� �ʿ���� �Լ��� ����� ����� �����ٴ� ���� �ذ����ִ� �������
	//CTest(void) = delete;
	int m_nData = 5;
};

// Ŭ���� �ܺο��� ����Ʈ ������ ����
//CTest::CTest(void) {}

int _tmain(int argc, _TCHAR* argv[])
{
	CTest a;
	cout << a.m_nData << endl;

	return 0;
}