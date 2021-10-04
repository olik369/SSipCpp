#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotationCW90Degree(vector<vector<int>> key) {
	int n = key.size();		//n행
	int m = key[0].size();	//m열

	//n행을 만들고 m열을 넣고 모든원소는 0으로 초기화
	vector<vector<int>> new_key(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//90도 회전했을때의 각행렬의 원소값 대입
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

	//큰 자물쇠 만들기
	vector<vector<int>> largeLock(3 * n, vector<int>(3 * m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			largeLock[i + n][j + m] = lock[i][j];
		}
	}

	int key_n = key.size();
	int key_m = key[0].size();

	//우선 회전하는 경우의 수만큼
	for (int rot_number = 0; rot_number < 4; rot_number++) {
		key = rotationCW90Degree(key);

		//key가 이제 한 칸씩 움직임
		for (int x = 0; x < 2 * n; x++) {
			for (int y = 0; y < 2 * m; y++) {
				//움직인 열쇠를 자물쇠에 더하기
				for (int i = 0; i < key_n; i++) {
					for (int j = 0; j < key_m; j++) {
						largeLock[i + x][j + y] += key[i][j];
					}
				}
				//열쇠 체크
				if (checkKey(largeLock) == true) return true;

				//맞지 않으면 채운 열쇠를 빼기
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