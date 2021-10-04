#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotationCW90Degree(vector<vector<int>> key) {
	int n = key.size();		//n��
	int m = key[0].size();	//m��

	//n���� ����� m���� �ְ� �����Ҵ� 0���� �ʱ�ȭ
	vector<vector<int>> new_key(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//90�� ȸ���������� ������� ���Ұ� ����
			new_key[n - 1 - j][i] = key[i][j];
		}
	}
	return new_key;
}

bool checkKey(vector<vector<int>> largeLock) {
	int lockLength = largeLock.size() / 3;

	for (int i = lockLength; i < 2 * lockLength; i++) {
		for (int j = lockLength; j < 2 * lockLength; j++) {
			if (largeLock[i][j] != 1) return false;
		}
	}

	return true;
}

bool solution(vector<vector<int>>key, vector<vector<int>> lock) {
	int n = lock.size();
	int m = lock[0].size();

	//ū �ڹ��� �����
	vector<vector<int>> largeLock(3 * n, vector<int>(3 * m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			largeLock[i + n][j + m] = lock[i][j];
		}
	}

	int key_n = key.size();
	int key_m = key[0].size();

	//�켱 ȸ���ϴ� ����� ����ŭ
	for (int rot_number = 0; rot_number < 4; rot_number++) {
		key = rotationCW90Degree(key);

		//key�� ���� �� ĭ�� ������
		for (int x = 0; x < 2 * n; x++) {
			for (int y = 0; y < 2 * m; y++) {
				//������ ���踦 �ڹ��迡 ���ϱ�
				for (int i = 0; i < key_n; i++) {
					for (int j = 0; j < key_m; j++) {
						largeLock[i + x][j + y] += key[i][j];
					}
				}
				//���� üũ
				if (checkKey(largeLock) == true) return true;

				//���� ������ ä�� ���踦 ����
				for (int i = 0; i < key_n; i++) {
					for (int j = 0; j < key_m; j++) {
						largeLock[i + x][j + y] -= key[i][j];
					}
				}
			}
		}
	}
	
	return false;
}

int main() {

}