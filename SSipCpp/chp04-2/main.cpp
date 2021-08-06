/* 함수의 오버로딩*/
//함수의 이름이 같더라도 인자가 다르면 다른 함수로 인식함

//#include <iostream>
//using namespace std;
//
//void print(int x) { cout << "int : " << x << endl; }
//void print(char x) { cout << "char : " << x << endl; }
//void print(double x) { cout << "double : " << x << endl; }
//
//int main() {
//	int a = 1;
//	char b = 'c';
//	double c = 3.2f;
//
//	print(a);
//	print(b);
//	print(c);
//
//	return 0;
//}

/* Date 클래스 */
//#include <iostream>
//using namespace std;
//
//class Date {
//	int year_;
//	int month_;
//	int day_;
//
//public:
//	void SetDate(int year, int month, int date);
//	void AddDay(int inc);
//	void AddMonth(int inc);
//	void AddYear(int inc);
//
//	int GetCurrentMonthTotalDays(int year, int month);
//
//	void ShowDate();
//};
//
//void Date::SetDate(int year, int month, int date) {
//	year_ = year;
//	month_ = month;
//	day_ = date;
//}
//
//int Date::GetCurrentMonthTotalDays(int year, int month) {
//	static int month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
//	if (month != 2) {
//		return month_day[month - 1];
//	}
//	else if (year % 4 == 0 && year % 100 != 0) {
//		return 29;
//	}
//	else {
//		return 28;
//	}
//}
//
//void Date::AddDay(int inc) {
//	while (true) {
//		//현재 달의 총 일수
//		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);
//
//		//같은 달 안에 들어온다면
//		if (day_ + inc <= current_month_total_days) {
//			day_ += inc;
//			return;
//		}
//		else {
//			inc -= (current_month_total_days - day_ + 1);
//			day_ = 1;
//			AddMonth(1);
//		}
//	}
//}
//
//void Date::AddMonth(int inc) {
//	AddYear((inc + month_ - 1) / 12);
//	month_ += inc % 12;
//	month_ = (month_ == 12 ? 12 : month_ % 12);
//}
//
//void Date::AddYear(int inc) {
//	year_ += inc;
//}
//
//void Date::ShowDate() {
//	cout << "오늘은 " << year_ << " 년" << month_ << " 월" << day_ << " 일 입니다 " << endl;
//}
//
//int main() {
//	Date day;
//	day.SetDate(2011, 3, 1);
//	day.ShowDate();
//
//	day.AddDay(30);
//	day.ShowDate();
//
//	day.AddDay(2000);
//	day.ShowDate();
//
//	day.SetDate(2012, 1, 31);  // 윤년
//	day.AddDay(29);
//	day.ShowDate();
//
//	day.SetDate(2012, 8, 4);
//	day.AddDay(2500);
//	day.ShowDate();
//	return 0;
//}

/* 생성자 */
#include <iostream>
using namespace std;

class Date {
	int year_;
	int month_;
	int day_;

public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	int GetCurrentMonthTotalDays(int year, int month);

	void ShowDate();

	Date(int year, int month, int date) {
		year_ = year;
		month_ = month;
		day_ = date;
	}
};

void Date::SetDate(int year, int month, int date) {
	year_ = year;
	month_ = month;
	day_ = date;
}

int Date::GetCurrentMonthTotalDays(int year, int month) {
	static int month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month != 2) {
		return month_day[month - 1];
	}
	else if (year % 4 == 0 && year % 100 != 0) {
		return 29;
	}
	else {
		return 28;
	}
}

void Date::AddDay(int inc) {
	while (true) {
		//현재 달의 총 일수
		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

		//같은 달 안에 들어온다면
		if (day_ + inc <= current_month_total_days) {
			day_ += inc;
			return;
		}
		else {
			inc -= (current_month_total_days - day_ + 1);
			day_ = 1;
			AddMonth(1);
		}
	}
}

void Date::AddMonth(int inc) {
	AddYear((inc + month_ - 1) / 12);
	month_ += inc % 12;
	month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) {
	year_ += inc;
}

void Date::ShowDate() {
	cout << "오늘은 " << year_ << " 년" << month_ << " 월" << day_ << " 일 입니다 " << endl;
}

int main() {
	Date day(2011, 3, 1);
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

/*
문제 2
수학 관련 소프트웨어를 만드는 회사에서 의뢰가 들어왔습니다.
중학생용 기하학 소프트웨워를 만드는 것인데요, 
클래스는 총 두 개로 하나는 Point 로 점에 관한 정보를 담는 것이고 
다른 하나는 Geometry 로 점들을 가지고 연산을 하는 클래스 입니다. 
즉 아래와 같은 두 클래스의 함수들을 모두 정의하세요 (난이도 : 上)
*/

//#include <iostream>
//using namespace std;
//
//class Point {
//public:
//    int x, y;
//
//    Point(int pos_x, int pos_y) {
//        x = pos_x;
//        y = pos_y;
//    }
//};
//
//class Geometry {
//public:
//    Geometry() {
//        num_points = 0;
//    }
//
//    void AddPoint(const Point& point) {
//        point_array[num_points++] = new Point(point.x, point.y);
//    }
//
//    // 모든 점들 간의 거리를 출력하는 함수 입니다.
//    void PrintDistance() {
//        for (int i = 0; i < num_points; i++) {
//            
//            cout << i << "번째 점과 각각의 점간의 거리" << endl;
//            
//            for (int j = 0; j < num_points; j++) {
//                
//                if (i == j) { continue; }
//                
//                double dist_x = point_array[j]->x - point_array[i]->x;
//                double dist_y = point_array[j]->y - point_array[i]->y;
//                double distance = sqrt(pow(dist_x, 2) + pow(dist_y, 2));
//                
//                cout << j << "번째 점 간 거리 : " << distance << endl;
//            }
//        }
//    }
//
//    // 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수 입니다.
//    // 참고적으로 임의의 두 점을 잇는 직선의 방정식을 f(x,y) = ax+by+c = 0
//    // 이라고 할 때 임의의 다른 두 점 (x1, y1) 과 (x2, y2) 가 f(x,y)=0 을 기준으로
//    // 서로 다른 부분에 있을 조건은 f(x1, y1) * f(x2, y2) <= 0 이면 됩니다.
//    void PrintNumMeets();
//
//private:
//    // 점 100 개를 보관하는 배열.
//    Point* point_array[100];
//    int num_points;
//};