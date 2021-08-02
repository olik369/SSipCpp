#include <iostream>
using namespace std;

//class Animal {
//private:
//	int food;
//	int weight;
//
//public:
//	void SetAnimal(int _food, int _weight) {
//		food = _food;
//		weight = _weight;
//	}
//
//	void IncreaseFood(int inc) {
//		food += inc;
//		weight += (inc / 3);
//	}
//
//	void ViewStat() {
//		cout << "�� ������ food : " << food << endl;
//		cout << "�� ������ weight : " << weight << endl;
//	}
//};
//
//int main() {
//	Animal animal;
//	animal.SetAnimal(100, 50);
//	animal.IncreaseFood(30);
//
//	animal.ViewStat();
//
//	return 0;
//}

//���� 1

/*
�������� �Ʒ��� ���� Date Ŭ������ ������ �Ϸ��� �մϴ�. 
SetDate �� ���״�� Date �Լ� ���θ� �ʱ�ȭ �ϴ� ���̰� 
AddDay, AddMonth, AddYear �� ��, ��, ���� ���ϴ� ��ŭ ���ϰ� �˴ϴ�. 
�� ���� ������ ���� ���� 2012 �� 2 �� 28 �Ͽ� 3 ���� ���ϸ� 
2012 �� 2 �� 31 ���� �Ǵ� ���� �ƴ϶� 2012 �� 3 �� 2 ���� �ǰ�����? (���̵� : ߾)
*/

class Date {
	int year_;
	int month_;  // 1 ���� 12 ����.
	int day_;    // 1 ���� 31 ����.

public:
	void SetDate(int year, int month, int date) {
		year_ = year;
		month_ = month;
		day_ = date;
	}

	void AddDay(int inc) {
		int temp = inc;
		while (temp > 0) {
			//28�� 2��(���� 2020��... 4�⿡ �ѹ���)
			if (month_ == 2) {
				if (year_ % 4 == 0) {
					//29�� �Ѵ�
					if ((day_ + temp) > 29) {
						month_ += 1;
						temp -= (29 - day_ + 1);
					}
					else {
						day_ += temp;
						temp = 0;
					}
				}
				else {
					//28�� �Ѵ�
					if ((day_ + temp) > 28) {
						month_ += 1;
						temp -= (28 - day_ + 1);
					}
					else {
						day_ += temp;
						temp = 0;
					}
				}
			}
			//30�� 4,6,9,11
			else if (month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11) {
				if ((day_ + temp) > 30) {
					month_ += 1;
					temp -= (30 - day_ + 1);
				}
				else {
					day_ += temp;
					temp = 0;
				}
			}
			//31�� 1,3,5,7,8,10,12
			else {
				if ((day_ + temp) > 31) {
					month_ += 1;
					temp -= (31 - day_ + 1);
				}
				else {
					day_ += temp;
					temp = 0;
				}
			}

			//12->13�� �Ǹ� ����
			if (month_ > 12) {
				year_ += 1;
				month_ = 1;
			}
		}
	}

	void AddMonth(int inc) {
		int temp = month_ + inc;

		while (temp > 12) {
			year_ += 1;
			temp -= 12;
		}
		month_ = temp;
	}

	void AddYear(int inc) {
		year_ += inc;
	}

	void ShowDate() {
		cout << year_ << "�� " << month_ << "�� " << day_ << "��" << endl;
	}
};

int main() {
	Date today;
	today.SetDate(2021, 8, 2);
	today.AddMonth(4);
	
	today.ShowDate();

	Date day;
	day.SetDate(2011, 3, 1);
	day.ShowDate();

	day.AddDay(30);
	day.ShowDate();

	day.AddDay(2000);
	day.ShowDate();

	day.SetDate(2012, 1, 31);  // ����
	day.AddDay(29);
	day.ShowDate();

	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();

	return 0;
}