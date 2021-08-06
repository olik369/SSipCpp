#include <iostream>
using namespace std;

//매개변수가 int에 대한 참조형식이다.
void TestFunc(int& rParam) {
	//피 호출자 함수에서 원본의 값을 변경했다.
	rParam = 100;
}

int main() {
	/*
	int nData = 10;

	//nData 변수에 대한 참조자 선언
	int& ref = nData;

	//참조자의 값을 변경하면 원본도 변경
	ref = 20;
	cout << nData << endl;

	//포인터를 쓰는 것과 비슷함
	int* pnData = &nData;
	*pnData = 30;
	cout << nData << endl;

	return 0;
	*/

	int nData = 0;

	//참조에 의한 인수 전달
	TestFunc(nData);
	cout << nData << endl;

	return 0;
}