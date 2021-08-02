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
//		cout << "이 동물의 food : " << food << endl;
//		cout << "이 동물의 weight : " << weight << endl;
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

//문제 1

/*
여러분은 아래와 같은 Date 클래스를 디자인 하려고 합니다. 
SetDate 는 말그대로 Date 함수 내부를 초기화 하는 것이고 
AddDay, AddMonth, AddYear 는 일, 월, 년을 원하는 만큼 더하게 됩니다. 
한 가지 주의할 점은 만일 2012 년 2 월 28 일에 3 일을 더하면 
2012 년 2 월 31 일이 되는 것이 아니라 2012 년 3 월 2 일이 되겠지요? (난이도 : 上)
*/

class Date {
	int year_;
	int month_;  // 1 부터 12 까지.
	int day_;    // 1 부터 31 까지.

public:
	void SetDate(int year, int month, int date) {
		year_ = year;
		month_ = month;
		day_ = date;
	}

	void AddDay(int inc) {
		int temp = inc;
		while (temp > 0) {
			//28일 2월(윤년 2020년... 4년에 한번씩)
			if (month_ == 2) {
				if (year_ % 4 == 0) {
					//29일 한달
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
					//28일 한달
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
			//30일 4,6,9,11
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
			//31일 1,3,5,7,8,10,12
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

			//12->13월 되면 실행
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
		cout << year_ << "년 " << month_ << "월 " << day_ << "일" << endl;
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

	day.SetDate(2012, 1, 31);  // 윤년
	day.AddDay(29);
	day.ShowDate();

	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();

	return 0;
}