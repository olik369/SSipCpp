#include <cstdio>
#include <tchar.h>

// �������� �ڵ�
class USERDATA
{
public:
	// ��� ���� ����
	int nAge;
	char szName[32];

	// ��� �Լ� ���� �� ����
	void Print(void)
	{
		//nAge�� szName�� Print() �Լ��� ���� ������ �ƴϴ�!
		printf("%d, %s\n", nAge, szName);
	}
};

// ������� �ڵ�
int _tmain(int argc, _TCHAR* argv[])
{
	USERDATA user = { 10, "ö��" };
	user.Print();

	return 0;
}