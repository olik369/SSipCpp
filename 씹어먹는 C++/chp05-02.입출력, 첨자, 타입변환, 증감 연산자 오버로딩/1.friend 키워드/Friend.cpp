#include "Friend.h"

using namespace std;

void func()
{
	A a;
	B b;

	// ��� private �Լ��� �ʵ�������� ���� ���������� ģ���̱� ������ ���� ������
	a.private_func();
	a.private_num = 2;

	//B�� A�� ģ������ A�� B�� ģ���� �������� �ʾ����Ƿ�
	//class B�� private����������� ���� �Ұ�!
	//b.y = 2;
}

void B::b()
{
	A a;

	// ��� private �Լ��� �ʵ�������� ģ���̱� ������ ���� �����ϴ�.
	a.private_func();
	a.private_num = 2;
}
