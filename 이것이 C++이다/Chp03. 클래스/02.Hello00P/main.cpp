#include <cstdio>

//�������� �ڵ�
class USERDATA {
public:
	//������� ����
	int nAge;
	char szName[32];

	//����Լ� ���� �� ����
	void Print(void) {
		//nAe�� szName�� Print() �Լ��� ���������� �ƴ�!
		printf("%d, %s\n", nAge, szName);
	}
};

//������� �ڵ�
int main() {
	USERDATA user = { 10,"ö��" };

	user.Print();

	return 0;
}
