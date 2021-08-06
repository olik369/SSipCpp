#include <iostream>
#include <cstdio>
#define ADD(a, b)((a) + (b))

using namespace std;

int Add(int a, int b) {
	return a + b;
}

inline int AddNew(int a, int b) {
	return a + b;
}

int main() {
	int a, b;
	scanf_s("%d%d", &a, &b);

	printf("ADD(): %d\n", ADD(a, b));
	printf("Add(): %d\n", Add(a, b));
	printf("AddNew(): %d", AddNew(a, b));

	return 0;
}