#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int n, m;
int indegree[32001];
vector<int> student[32001];
deque<int> Line;
void input() {
	cin >> n >> m;
	int winner, loser;
	while (m--) {
		cin >> winner >> loser;
		student[winner].push_back(loser);
		indegree[loser]++;
	}
}

// 위상정렬
void solution() {

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			Line.push_front(i);
		}
	}

	while (!Line.empty()) {
		int cur = Line.front();
		Line.pop_front();

		cout << cur << " ";
		for (int i = 0; i < student[cur].size(); i++) {
			indegree[student[cur][i]]--; // winner 한테 진놈들 화살표 없애줌
			// 이제 더이상 날 이긴놈이 없을때!!
			if (indegree[student[cur][i]] == 0) Line.push_front(student[cur][i]);
		}
	}

}

int main() {	

	input();
	solution();

	return 0;
}