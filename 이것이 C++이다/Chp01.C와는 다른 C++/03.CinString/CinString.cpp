#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	int nAge;
	cout << "���̸� �Է��ϼ���." << endl;
	cin >> nAge;

	char szJob[32];
	cout << "������ �Է��ϼ���" << endl;
	cin >> szJob;

	string strName;
	cout << "�̸��� �Է��ϼ���." << endl;
	cin >> strName;

	cout << "����� �̸��� " << strName << "�̰�, "
		<< "���̴� " << nAge << "���̸�, "
		<< "������ " << szJob << "�Դϴ�." << endl;

	return 0;
}