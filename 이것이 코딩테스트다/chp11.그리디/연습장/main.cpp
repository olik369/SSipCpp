#include <bits/stdc++.h>

using namespace std;

//��������<int, ���Ұ�>
//bool compare(pair<int, int>a, pair<int, int>b) {
//	return a.second < b.second;
//}
//
//int solution(vector<int> food_times, long long k) {
//	//��ü ������ �Դ� �ð����� k�� ũ�ų� ���ٸ� -1
//	long long summary = 0;
//	for (int i = 0; i < food_times.size(); i++) {
//		summary += food_times[i];
//	}
//	if (summary <= k) return -1;
//
//	//�ð��� ���� ���ĺ��� ���� �ϹǷ� �켱���� ť�� �̿�
//	priority_queue<pair<int, int>> pq;
//	for (int i = 0; i < food_times.size(); i++) {
//		//(���Ľð�, ���� ��ȣ) ���·� �켱���� ť�� ����
//		pq.push({ -food_times[i], i + 1 });	//C++�� �ִ����̹Ƿ� �翬�� ������������ �����ϱ� ���� '-' ����
//	}
//	
//	summary = 0;	//�Ա� ���� ����� �ð�
//	long long previous = 0; //������ �� ���� ���� �ð�
//	long long length = food_times.size();	//���� ������ ����
//
//	//summary + (������ ���� �ð� - ���� ���� �ð�) * ���� ���� ������ k ��
//	while (summary + ((-pq.top().first - previous) * length) <= k) {
//		int nowTime = -pq.top().first;
//		pq.pop();
//		summary += (nowTime - previous) * length;
//		length -= 1;	//�� ���� ���� ����
//		previous = nowTime;	//���� ���� �ð� �缳��
//	}
//
//	//���� ���� �߿��� �� ��° �������� Ȯ���Ͽ� ���
//	vector<pair<int, int>> result;
//	while (pq.empty() == false) {
//		int food_time = -pq.top().first;
//		int num = pq.top().second;
//		pq.pop();
//		result.push_back({ food_time,num });
//	}
//	sort(result.begin(), result.end(), compare);	//���� ��ȣ �������� �������� ����
//	return result[(k - summary) % length].second;
//}
int solution(vector<int>food_times, long long k) {
	long long summary = 0;
	for (int i = 0; i < food_times.size(); i++) {
		summary += food_times[i];
	}

	if (summary <= k) return -1;

	priority_queue<pair<int, int>> pq;	//pq = {time, index}
	for (int i = 0; i < food_times.size(); i++) {
		int food_time = -food_times[i];
		int food_num = i + 1;
		pq.push({ food_time,food_num });
	}

	summary = 0;
	long long length = food_times.size();
	long long previous_min = 0;
	//sum + (now - prev) * length <= k �� �Ǵ� ���� ���� ��� �ݺ��ؼ� ������
	while (summary + ((-pq.top().first - previous_min) * length) <= k) {
		summary += (-pq.top().first - previous_min) * length;
		previous_min = -pq.top().first;
		pq.pop();
		length -= 1;
	}

	vector<int> result;
	while (pq.empty() == false) {
		int num = pq.top().second;
		pq.pop();
		result.push_back(num);
	}
	sort(result.begin(), result.end());
	return result[(k - summary) % length];
}

int main() {

}