#include "staticmarine.h"

int Marine::total_marine_num = 0;
int main() {
	/*Marine marine1(2, 3);
	Marine marine2(3, 5);

	marine1.show_status();
	marine2.show_status();*/

	/*Marine marine1(2, 3, 10);
	marine1.show_status();

	Marine marine2(3, 5, 10);
	marine2.show_status();

	std::cout << std::endl << "마린 1이 마린 2를 공격! " << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();*/

	Marine marine1(2, 3, 5);
	Marine::show_total_marine();

	Marine marine2(3, 5, 10);
	Marine::show_total_marine();

	create_marine();

	std::cout << std::endl << "마린 1 이 마린 2를 공격! " << std::endl;
	marine2.be_attacked(marine1.attack());

	marine1.show_status();
	marine2.show_status();
}