//진짜 개멘붕;;
#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> apple;
queue<pair<int, char>> rot_info;

//동, 남, 서, 북
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int result = 0;

int main() {
	//뱀이 1,1에서부터 시작 , 방향 : 동(0), 남(1), 서(2), 북(3)
	int snake_head[3] = { 1,1,0 };
	int N, K, L;	//N보드 크기, K사과 갯수, L방향전환 횟수
	cin >> N >> K;

	//snake 몸통 정보 저장변수
	vector<vector<int>> snake_body(N + 1, vector<int>(N + 1));
	vector<pair<int, int>> snake_tail;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		apple.push({ x,y });
	}

	cin >> L;

	for (int i = 0; i < L; i++) {
		int X;	//x초 후
		char direction;	//방향, L:왼쪽 D:오른쪽
		cin >> X >> direction;
		rot_info.push({ X,direction });
	}

	int rot_index = 0;
	int apple_index = 0;
	//뱀 게임 시작!
	while (true) {
		result += 1;
		bool takeApple = false;
		
		//뱀의 머리 움직임
		int next_snake_x = snake_head[0] + dx[snake_head[2]];
		int next_snake_y = snake_head[1] + dy[snake_head[2]];
		

		//사과 먹는것 처리
		if (apple.empty() == false) {
			if (apple.front().first == next_snake_x && apple.front().second == next_snake_y) {
				//꼬리 추가
				snake_tail.insert(snake_tail.begin(), { snake_head[0],snake_head[1] });
				apple.pop();
				takeApple = true;
				//snake_tail.push_back({ snake_head[0],snake_head[1] });
			}
		}

		//뱀의 꼬리 움직임
		if (takeApple == false) {
				for (int i = 0; i < snake_tail.size(); i++) {
					int next_position_x, next_position_y;
					if (i == 0) {
						next_position_x = next_snake_x;
						next_position_y = next_snake_y;
					}
					else {
						next_position_x = snake_tail[i - 1].first;
						next_position_y = snake_tail[i - 1].second;
					}
					snake_tail[i].first = next_position_x;
					snake_tail[i].second = next_position_y;
				}
		}
		//뱀 몸통 위치정보 맵 초기화
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				snake_body[i][j] = 0;
			}
		}

		//뱀 몸통 위치정보 맵 저장
		for (int i = 0; snake_tail.size(); i++) {
			snake_body[snake_tail[i].first][snake_tail[i].second] = 1;
		}

		//회전 처리
		if (rot_info.empty() == false) {
			if (rot_info.front().first == result) {

				if (rot_info.front().second == 'D') {
					snake_head[2] = (snake_head[2] + 1) % 4;
				}
				else {
					snake_head[2] = (snake_head[2] - 1) % 4;
				}

				rot_info.pop();
			}
		}


		//1. 벽에 닿는 경우
		if (next_snake_x == 0 || next_snake_x == N + 1 || next_snake_y == 0 || next_snake_y == N + 1) break;
		
		//2. 내 몸통에 머리가 닿는 경우
		if (snake_body[next_snake_x][next_snake_y] == 1) break;

		//3. 둘다 아닌경우
		snake_head[0] = next_snake_x;
		snake_head[1] = next_snake_y;
	}

	cout << result << endl;
}