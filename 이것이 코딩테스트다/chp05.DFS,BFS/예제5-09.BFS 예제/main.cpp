#include <bits/stdc++.h>

using namespace std;

bool visited[9];
vector<int> graph[9];

void BFS(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (q.empty() == false) {
        int x = q.front();
        q.pop();
        cout << x << ' ';

        for (int i = 0; i < (int)graph[x].size(); i++) {
            auto y = graph[x][i];
            if (visited[y] == false) {
				q.push(y);
                visited[y] = true;
            }
        }
    }
}

int main() {
    // ��� 1�� ����� ��� ���� ���� 
    graph[1].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(8);

    // ��� 2�� ����� ��� ���� ���� 
    graph[2].push_back(1);
    graph[2].push_back(7);

    // ��� 3�� ����� ��� ���� ���� 
    graph[3].push_back(1);
    graph[3].push_back(4);
    graph[3].push_back(5);

    // ��� 4�� ����� ��� ���� ���� 
    graph[4].push_back(3);
    graph[4].push_back(5);

    // ��� 5�� ����� ��� ���� ���� 
    graph[5].push_back(3);
    graph[5].push_back(4);

    // ��� 6�� ����� ��� ���� ���� 
    graph[6].push_back(7);

    // ��� 7�� ����� ��� ���� ���� 
    graph[7].push_back(2);
    graph[7].push_back(6);
    graph[7].push_back(8);

    // ��� 8�� ����� ��� ���� ���� 
    graph[8].push_back(1);
    graph[8].push_back(7);

    BFS(1);
}