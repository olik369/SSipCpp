#include <bits/stdc++.h>

using namespace std;

//오름차순<int, 비교할값>
//bool compare(pair<int, int>a, pair<int, int>b) {
//	return a.second < b.second;
//}
//
//int solution(vector<int> food_times, long long k) {
//	//전체 음식을 먹는 시간보다 k가 크거나 같다면 -1
//	long long summary = 0;
//	for (int i = 0; i < food_times.size(); i++) {
//		summary += food_times[i];
//	}
//	if (summary <= k) return -1;
//
//	//시간이 작은 음식부터 빼야 하므로 우선순위 큐를 이용
//	priority_queue<pair<int, int>> pq;
//	for (int i = 0; i < food_times.size(); i++) {
//		//(음식시간, 음식 번호) 형태로 우선순위 큐에 삽입
//		pq.push({ -food_times[i], i + 1 });	//C++은 최대힙이므로 당연히 오름차순으로 정렬하기 위해 '-' 붙임
//	}
//	
//	summary = 0;	//먹기 위해 사용한 시간
//	long long previous = 0; //직전에 다 먹은 음식 시간
//	long long length = food_times.size();	//남은 음식의 개수
//
//	//summary + (현재의 음식 시간 - 이전 음식 시간) * 현재 음식 개수와 k 비교
//	while (summary + ((-pq.top().first - previous) * length) <= k) {
//		int nowTime = -pq.top().first;
//		pq.pop();
//		summary += (nowTime - previous) * length;
//		length -= 1;	//다 먹은 음식 제외
//		previous = nowTime;	//이전 음식 시간 재설정
//	}
//
//	//남은 음식 중에서 몇 번째 음식인지 확인하여 출력
//	vector<pair<int, int>> result;
//	while (pq.empty() == false) {
//		int food_time = -pq.top().first;
//		int num = pq.top().second;
//		pq.pop();
//		result.push_back({ food_time,num });
//	}
//	sort(result.begin(), result.end(), compare);	//음식 번호 기준으로 오름차순 정렬
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
	//sum + (now - prev) * length <= k 이 되는 조건 동안 계속 반복해서 빼야함
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