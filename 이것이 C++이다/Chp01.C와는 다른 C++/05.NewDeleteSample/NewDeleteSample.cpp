#include <iostream>
using namespace std;

int main() {
	/* NewDelete */
	//// �ν��Ͻ��� �������� �����ϴ� ���
	//int* pData = new int;
	//
	////�ʱ갪�� ����ϴ� ���
	//int* pNewData = new int(10);

	//*pData = 5;
	//std::cout << *pData << std::endl;
	//std::cout << *pNewData << std::endl;

	//delete pData;
	//delete pNewData;

	/* NewDeleteArray */
	//��ü�� �迭 ���·� ���� ����
	int* arr = new int[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = (i + 1) * 10;
	}
	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << endl;
	}

	//�迭 ���·� ������ ����� �ݵ�� �迭 ���¤��� ���� �����Ѵ�!
	delete[] arr;

	return 0;
}