#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int nAge;
	cout << "나이를 입력하세요." << endl;
	cin >> nAge;

	char szJob[32];
	cout << "직업을 입력하세요" << endl;
	cin >> szJob;

	string strName;
	cout << "이름을 입력하세요." << endl;
	cin >> strName;

	cout << "당신의 이름은 " << strName << "이고, "
		<< "나이는 " << nAge << "살이며, "
		<< "직업은 " << szJob << "입니다." << endl;

	return 0;
}