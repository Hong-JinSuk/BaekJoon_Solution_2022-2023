#include <iostream>
#include <vector>
#include <deque>
#define endl "\n"
using namespace std;

int T, n;

int isTeam[100001]; // 1 : 지나감, -1 : 이미 팀이 있음, 0 : 아직 검사안함 
vector<int> pick(100001);
deque<int> q;

void find_cycle(int Last) {
	bool isCycle = false;
	if (Last == -1) { // 이미 팀이 있으면 못구함.
		while (!q.empty()) { 
			int cur = q.front();
			q.pop_front();
			isTeam[cur] = 1; // 지금까지 검사한 친구들 방문표시
		}
		return;
	}
	while (!q.empty()) { 
		int cur = q.front();
		q.pop_front();
		if (Last == cur) { // 싸이클이 생기면 여기서부터는 팀으로 해줌
			isCycle = true;
		}
		if (isCycle) {
			isTeam[cur] = -1;
		}
		else {
			isTeam[cur] = 1;
		}
	}
	return;
}

void search(int root, int next) {
	q.push_back(next);
	if (isTeam[next] == -1) { // 팀이 있는 경우
		q.pop_back(); // 팀이 있는 친구는 빼고 나머지는 방문표시하러감
		find_cycle(-1);
		return;
	}
	if (isTeam[next] == 1) { // 방문한적 있는 길인 경우 싸이클 검사
		q.pop_back(); // 이미 방문한 친구는 빼고 검사해줌.
		find_cycle(next);
		return;
	}
	isTeam[next] = 1;
	search(root, pick[next]);
	return;
}

void solution() {
	for (int i = 1; i <= n; i++) {
		if (isTeam[i] == 0) { // 아직 팀검사 X
			q.push_back(i);
			isTeam[i] = 1;
			search(i, pick[i]);
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> T;
	for(int i=0; i<T; i++) {
		fill(isTeam, isTeam + 100001, false);
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> pick[j];
		}
		solution();
		int answer = 0;
		for (int k = 1; k <= n; k++) {
			if (isTeam[k] == 1) answer++;
			// cout << isTeam[k] << " ";
		}
		cout << answer << endl;
	}
	

	return 0;
}