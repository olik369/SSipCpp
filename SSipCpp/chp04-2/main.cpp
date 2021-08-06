/* �Լ��� �����ε�*/
//�Լ��� �̸��� ������ ���ڰ� �ٸ��� �ٸ� �Լ��� �ν���

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

/* Date Ŭ���� */
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
//		//���� ���� �� �ϼ�
//		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);
//
//		//���� �� �ȿ� ���´ٸ�
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
//	cout << "������ " << year_ << " ��" << month_ << " ��" << day_ << " �� �Դϴ� " << endl;
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
//	day.SetDate(2012, 1, 31);  // ����
//	day.AddDay(29);
//	day.ShowDate();
//
//	day.SetDate(2012, 8, 4);
//	day.AddDay(2500);
//	day.ShowDate();
//	return 0;
//}

/* ������ */
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
		//���� ���� �� �ϼ�
		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

		//���� �� �ȿ� ���´ٸ�
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
	cout << "������ " << year_ << " ��" << month_ << " ��" << day_ << " �� �Դϴ� " << endl;
}

int main() {
	Date day(2011, 3, 1);
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

/*
���� 2
���� ���� ����Ʈ��� ����� ȸ�翡�� �Ƿڰ� ���Խ��ϴ�.
���л��� ������ ����Ʈ������ ����� ���ε���, 
Ŭ������ �� �� ���� �ϳ��� Point �� ���� ���� ������ ��� ���̰� 
�ٸ� �ϳ��� Geometry �� ������ ������ ������ �ϴ� Ŭ���� �Դϴ�. 
�� �Ʒ��� ���� �� Ŭ������ �Լ����� ��� �����ϼ��� (���̵� : ߾)
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
//    // ��� ���� ���� �Ÿ��� ����ϴ� �Լ� �Դϴ�.
//    void PrintDistance() {
//        for (int i = 0; i < num_points; i++) {
//            
//            cout << i << "��° ���� ������ ������ �Ÿ�" << endl;
//            
//            for (int j = 0; j < num_points; j++) {
//                
//                if (i == j) { continue; }
//                
//                double dist_x = point_array[j]->x - point_array[i]->x;
//                double dist_y = point_array[j]->y - point_array[i]->y;
//                double distance = sqrt(pow(dist_x, 2) + pow(dist_y, 2));
//                
//                cout << j << "��° �� �� �Ÿ� : " << distance << endl;
//            }
//        }
//    }
//
//    // ��� ������ �մ� ������ ���� ������ ���� ������ִ� �Լ� �Դϴ�.
//    // ���������� ������ �� ���� �մ� ������ �������� f(x,y) = ax+by+c = 0
//    // �̶�� �� �� ������ �ٸ� �� �� (x1, y1) �� (x2, y2) �� f(x,y)=0 �� ��������
//    // ���� �ٸ� �κп� ���� ������ f(x1, y1) * f(x2, y2) <= 0 �̸� �˴ϴ�.
//    void PrintNumMeets();
//
//private:
//    // �� 100 ���� �����ϴ� �迭.
//    Point* point_array[100];
//    int num_points;
//};