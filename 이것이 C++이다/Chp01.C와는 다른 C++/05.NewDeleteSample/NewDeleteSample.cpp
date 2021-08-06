#include <iostream>
using namespace std;

int main() {
	/* NewDelete */
	//// 인스턴스만 동적으로 생성하는 경우
	//int* pData = new int;
	//
	////초깃값을 기술하는 경우
	//int* pNewData = new int(10);

	//*pData = 5;
	//std::cout << *pData << std::endl;
	//std::cout << *pNewData << std::endl;

	//delete pData;
	//delete pNewData;

	/* NewDeleteArray */
	//객체를 배열 형태로 동적 생성
	int* arr = new int[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = (i + 1) * 10;
	}
	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << endl;
	}

	//배열 형태로 생성한 대상은 반드시 배열 형태ㄹ를 통해 삭제한다!
	delete[] arr;

	return 0;
}