#include <stdio.h>

// �������� �ڵ�
typedef struct _USERDATA 
{
	int nAge;
	char szName[32];
	void(*Print)(struct USERDATA*);
} USERDATA;

void PrintData(USERDATA* user)
{
	printf("%d, %s", user->nAge, user->szName);
}

// ������� �ڵ�
int main(void)
{
	USERDATA user = { 20, "ö��", PrintData };
	//printf("%d, %s", user.nAge, user.szName);	//1�ܰ�
	//PrintData(&user);							//2�ܰ�
	user.Print(&user);

	return 0;
}