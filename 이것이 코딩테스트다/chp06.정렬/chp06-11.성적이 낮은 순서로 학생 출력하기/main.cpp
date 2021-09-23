#include <bits/stdc++.h>

using namespace std;

class Student {
public:
	string name;
	int score;

	Student(string _name, int _score) {
		this->name = _name;
		this->score = _score;
	}

	bool operator< (Student& other) {
		return this->score < other.score;
	}
};

int N;
vector<Student>	arr;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		string inputName;
		int inputScore;
		cin >> inputName >> inputScore;
		arr.push_back(Student(inputName, inputScore));
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		cout << arr[i].name << ' ';
	}

	return 0;
}