#include <cstdio>

//제작자의 코드
class USERDATA {
public:
	//멤버변수 선언
	int nAge;
	char szName[32];

	//멤버함수 선언 및 정의
	void Print(void) {
		//nAe와 szName은 Print() 함수의 지역변수가 아님!
		printf("%d, %s\n", nAge, szName);
	}
};

//사용자의 코드
int main() {
	USERDATA user = { 10,"철수" };

	user.Print();

	return 0;
}
