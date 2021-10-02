#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotateMatrixBy90Degree(vector<vector<int>>a) {
	int n = a.size();	//행 길이 계산
	int m = a[0].size();	//열 길이 계산
	vector<vector<int>> result(n, vector<int>(m));	//결과 리스트

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result[n - 1 - j][i] = a[i][j];
		}
	}
	return result;
}

bool check(vector<vector<int>>newLock) {
	int lockLength = newLock.size() / 3;
	for (int i = lockLength; i < 2 * lockLength; i++) {
		for (int j = lockLength; j < 2 * lockLength; j++) {
			if (newLock[i][j] != 1) return false;
		}
	}
	return true;
}

bool solution(vector<vector<int>>key, vector<vector<int>> lock) {
	int n = lock.size();
	int m = key.size();
	//자물쇠의 크기를 3배로 변환
	vector<vector<int>> newLock(n * 3, vector<int>(n * 3));
	//중앙에 기존 좌물쇠 넣기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			newLock[i + n][j + n] = lock[i][j];
		}
	}

	for (int rotation = 0; rotation < 4; rotation++) {
		key = rotateMatrixBy90Degree(key);
		for (int x = 0; x < 2 * n; x++) {
			for (int y = 0; y < 2 * n; y++) {
				//열쇠 끼워보기
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) {
						newLock[x + i][y + j] += key[i][j];
					}
				}
				if (check(newLock) == true) return true;

				for (int i = 0; i < m; i++) {
					for (int j = 0; j < m; j++) {
						newLock[x + i][y + j] -= key[i][j];
					}
				}
			}
		}
	}
	return false;
}

int main() {

}