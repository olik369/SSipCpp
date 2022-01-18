#include "Complex.h"

using namespace std;

Complex::Complex(const char* str)
{
	// �Է� ���� ���ڿ��� �м��Ͽ� real �κа� img �κ��� ã�ƾ� �Ѵ�.
	// ���ڿ��� ���� ������ �����ϴ� "[��ȣ](�Ǽ���)(��ȣ)i(�����)"
	// �� �� �� ���� ��ȣ�� ���� �����մϴ�. (������ + �� ����)

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

	// pos_i = -1�̸� �Ǽ�
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
	// ���� index��ġ�� �ڹٲ�� 0�� ������
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
		else break; // �̻��� ���ڿ��� �� ���
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
