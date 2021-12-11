#include "staticmarine.h"
#include "returnref.h"

void create_marine() {
	Marine marine3(10, 10, 4);
	Marine::show_total_marine();
}

int main() {
	/*Marine* marines[100];
	marines[0] = new Marine(2, 3, 10);
	Marine::show_total_marine();

	marines[1] = new Marine(3, 5, 10);
	Marine::show_total_marine();

	create_marine();

	cout << endl << "마린 0 이 마린 1를 두 번 공격! " << endl;
	marines[1]->be_attacked(marines[0]->attack()).be_attacked(marines[0]->attack());

	marines[0]->show_status();
	marines[1]->show_status();

	delete marines[0];
	delete marines[1];*/

	A a(5);
	a.show_x();

	int& c = a.access_x();
	c = 4;
	a.show_x();

	int d = a.access_x();
	d = 3;
	a.show_x();
	
	//아래는 오류
	//int& e = a.get_x();
	//e = 2;
	//a.show_x();

	int f = a.get_x();
	f = 1;
	a.show_x();
}