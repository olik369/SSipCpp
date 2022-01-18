#include "Complex.h"

using namespace std;

Complex::Complex(const char* str)
{
	// 입력 받은 문자열을 분석하여 real 부분과 img 부분을 찾아야 한다.
	// 문자열의 꼴은 다음과 같습니다 "[부호](실수부)(부호)i(허수부)"
	// 이 때 맨 앞의 부호는 생략 가능합니다. (생략시 + 라 가정)

	real = 0.0;
	img = 0.0;
	int begin = 0, end = strlen(str);

	int pos_i = -1;
	for (int i = 0; i < end; i++) {
		if (str[i] == 'i') {
			pos_i = i;
			break;
		}
	}

	// pos_i = -1이면 실수
	if (pos_i == -1) {
		real = get_number(str, 0, end - 1);
	}
	else {
		real = get_number(str, 0, pos_i - 2);
		img = get_number(str, pos_i + 1, end - 1);

		if (pos_i >= 1 && str[pos_i - 1] == '-') {
			img *= -1.0;
		}
	}
}

//Complex Complex::operator+(const Complex& c) const
//{
//	Complex temp(real + c.real, img + c.img);
//	return temp;
//}

Complex Complex::operator-(const Complex& c) const
{
	Complex temp(real - c.real, img - c.img);
	return temp;
}

Complex Complex::operator*(const Complex& c) const
{
	double _real = real * c.real - img * c.img;
	double _img = real * c.img + c.real * img;
	return Complex(_real, _img);
}

Complex Complex::operator/(const Complex& c) const
{
	double _real = (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img);
	double _img = (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img);
	return Complex(_real, _img);
}

Complex& Complex::operator=(const Complex& c)
{
	real = c.real;
	img = c.img;
	return *this;
}

Complex& Complex::operator+=(const Complex& c)
{
	*this = *this + c;
	return *this;
}

Complex& Complex::operator-=(const Complex& c)
{
	*this = *this - c;
	return *this;
}

Complex& Complex::operator*=(const Complex& c)
{
	*this = (*this) * c;
	return *this;
}

Complex& Complex::operator/=(const Complex& c)
{
	*this = (*this) / c;
	return *this;
}

void Complex::println() const
{
	cout << "( " << real << " , " << img << " ) " << endl;
}

double Complex::get_number(const char* str, int from, int to) const
{
	bool minus = false;
	// 읽을 index위치가 뒤바뀌면 0을 리턴함
	if (from > to) return 0;

	if (str[from] == '-') minus = true;
	if (str[from] == '-' || str[from] == '+') from++;

	double num = 0.0;
	double decimal = 1.0;

	bool integer_part = true;
	for (int i = from; i <= to; i++) {
		if (isdigit(str[i]) && integer_part) {
			num *= 10.0;
			num += (str[i] - '0');
		}
		else if (str[i] == '.') {
			integer_part = false;
		}
		else if (isdigit(str[i]) && !integer_part) {
			decimal /= 10.0;
			num += ((str[i] - '0') * decimal);
		}
		else break; // 이상한 문자열이 올 경우
	}

	if (minus) num *= -1.0;

	return num;
}

Complex operator+(const Complex& a, const Complex& b)
{
	Complex temp(a.real + b.real, a.img + b.img);
	return temp;
}

ostream& operator<<(ostream& os, const Complex& c)
{
	cout << "( " << c.real << " , " << c.img << " ) ";
	return os;
}
