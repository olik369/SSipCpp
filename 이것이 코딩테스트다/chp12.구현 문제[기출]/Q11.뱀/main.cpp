//��¥ �����;;
#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> apple;
queue<pair<int, char>> rot_info;

//��, ��, ��, ��
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int result = 0;

int main() {
	//���� 1,1�������� ���� , ���� : ��(0), ��(1), ��(2), ��(3)
	int snake_head[3] = { 1,1,0 };
	int N, K, L;	//N���� ũ��, K��� ����, L������ȯ Ƚ��
	cin >> N >> K;

	//snake ���� ���� ���庯��
	vector<vector<int>> snake_body(N + 1, vector<int>(N + 1));
	vector<pair<int, int>> snake_tail;

	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		apple.push({ x,y });
	}

	cin >> L;

	for (int i = 0; i < L; i++) {
		int X;	//x�� ��
		char direction;	//����, L:���� D:������
		cin >> X >> direction;
		rot_info.push({ X,direction });
	}

	int rot_index = 0;
	int apple_index = 0;
	//�� ���� ����!
	while (true) {
		result += 1;
		bool takeApple = false;
		
		//���� �Ӹ� ������
		int next_snake_x = snake_head[0] + dx[snake_head[2]];
		int next_snake_y = snake_head[1] + dy[snake_head[2]];
		

		//��� �Դ°� ó��
		if (apple.empty() == false) {
			if (apple.front().first == next_snake_x && apple.front().second == next_snake_y) {
				//���� �߰�
				snake_tail.insert(snake_tail.begin(), { snake_head[0],snake_head[1] });
				apple.pop();
				takeApple = true;
				//snake_tail.push_back({ snake_head[0],snake_head[1] });
			}
		}

		//���� ���� ������
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
		//�� ���� ��ġ���� �� �ʱ�ȭ
		for (int i = 1; i < N + 1; i++) {
			for (int j = 1; j < N + 1; j++) {
				snake_body[i][j] = 0;
			}
		}

		//�� ���� ��ġ���� �� ����
		for (int i = 0; snake_tail.size(); i++) {
			snake_body[snake_tail[i].first][snake_tail[i].second] = 1;
		}

		//ȸ�� ó��
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


		//1. ���� ��� ���
		if (next_snake_x == 0 || next_snake_x == N + 1 || next_snake_y == 0 || next_snake_y == N + 1) break;
		
		//2. �� ���뿡 �Ӹ��� ��� ���
		if (snake_body[next_snake_x][next_snake_y] == 1) break;

		//3. �Ѵ� �ƴѰ��
		snake_head[0] = next_snake_x;
		snake_head[1] = next_snake_y;
	}

	cout << result << endl;
}