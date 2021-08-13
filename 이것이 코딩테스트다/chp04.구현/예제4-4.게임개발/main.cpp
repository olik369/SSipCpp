#include <bits/stdc++.h>
using namespace std;

int N, M;	//N X M 맵 생성
int x, y, direction;	//x : 상하, y : 좌우, direction : 방향
// 북(0), 동(1), 남(2), 서(3)
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//방문정보
int d[50][50];

//맵 정보
int arr[50][50];

void TurnLeft() {
	direction--;

	if (direction < 0) { direction = 3; }
}

int main() {
	cin >> N >> M;
	cin >> x >> y >> direction;

	//방문 횟수
	int count = 0;

	//처음 위치한곳 방문처리 및 방문횟수 증가
	d[x][y] = 1;
	count++;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int x;
			cin >> x;
			arr[i][j] = x;
		}
	}

	auto rotCount = 0;
	while (true) {
		TurnLeft();
		rotCount++;
		auto nx = x + dx[direction];
		auto ny = y + dy[direction];
		
		if (arr[nx][ny] == 0 && d[nx][ny] == 0) {
			x = nx;
			y = ny;
			d[x][y] = 1;
			count++;
			rotCount = 0;
		}

		if (rotCount == 4) {
			nx = x - dx[direction];
			ny = y - dy[direction];
			if (arr[nx][ny] == 1) {
				break;
			}
			else {
				rotCount = 0;
				x = nx;
				y = ny;
			}
		}
	}

	cout << count << endl;

	return 0;
}