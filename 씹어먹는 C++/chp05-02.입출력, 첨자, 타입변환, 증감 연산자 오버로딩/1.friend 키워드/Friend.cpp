#include "Friend.h"

using namespace std;

void func()
{
	A a;
	B b;

	// 비록 private 함수의 필드들이지만 위와 마찬가지로 친구이기 때문에 접근 가능함
	a.private_func();
	a.private_num = 2;

	//B는 A의 친구지만 A는 B의 친구라 선언하지 않았으므로
	//class B의 private멤버변수에는 접근 불가!
	//b.y = 2;
}

void B::b()
{
	A a;

	// 비록 private 함수의 필드들이지만 친구이기 때문에 접근 가능하다.
	a.private_func();
	a.private_num = 2;
}
