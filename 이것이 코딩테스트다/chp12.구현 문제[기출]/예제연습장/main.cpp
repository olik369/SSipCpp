#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
	int result = (int)s.size();

	for (int step = 1; step <= s.size(); step++) {
		string compressed = "";
		string prev = s.substr(0, step);
		int cnt = 1;

		for (int i = step; i < s.size(); i += step) {
			if (prev == s.substr(i, step)) cnt++;
			else {
				compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
				prev = s.substr(i, step);
				cnt = 1;
			}
		}
		compressed += (cnt >= 2) ? to_string(cnt) + prev : prev;
		result = min(result, (int)compressed.size());
	}
	return result;
}

int main() {

}