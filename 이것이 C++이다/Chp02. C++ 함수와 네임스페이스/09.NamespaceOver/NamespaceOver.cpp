#include <iostream>
using namespace std;

//����(����� ���Ҽ�)
void TestFunc(void) { cout << "::TestFunc()" << endl; }

namespace TEST {
	//TEST ���ӽ����̽� �Ҽ�
	void TestFunc() {
		cout << "TEST::TestFunc()" << endl;
	}
}

namespace MYDATA {
	//MYDATA ���ӽ����̽� �Ҽ�
	void TestFunc() {
		cout << "DATA::TestFunc()" << endl;
	}
}

int main() {
	TestFunc();		//������ ����
	::TestFunc();	//����� ����
	TEST::TestFunc();
	MYDATA::TestFunc();

	return 0;
}