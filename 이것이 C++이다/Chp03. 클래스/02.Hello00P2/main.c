#include <stdio.h>

// 제작자의 코드
typedef struct USERDATA
{
	int nAge;
	char szName[32];
} USERDATA;

void PrintData(USERDATA* pUser)
{
	printf("%d, %s\n", pUser->nAge, pUser->szName);
}

// 사용자의 코드
int main(void)
{
	USERDATA user = { 20, "철수" };
	//printf("%d, %s\n", user.nAge, user.szName);	//1단계
	PrintData(&user);								//2단계

	// 이 코드에서 말하고자 하는 것은 출력을 위한 방법을 굳이 사용자가 알필요 없다는 것임!
	// 이와 같은 역할을 수행하는 함수를 '인터페이스 함수'라고 함!
	return 0;
}