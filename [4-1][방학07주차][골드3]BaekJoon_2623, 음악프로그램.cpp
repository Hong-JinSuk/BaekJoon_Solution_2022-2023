#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int n, m;
int indegree[1050];
vector<int> Back[1050];
void input() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int num, num2;
		cin >> num;
		vector<int> Case;
		for (int j = 0; j < num; j++) {
			cin >> num2;
			Case.push_back(num2);
		}
		for (int k = 1; k < Case.size(); k++) {
			Back[Case[k-1]].push_back(Case[k]);
			indegree[Case[k]]++;
		}
	}
}

vector<int> solution() {
	vector<int> answer;
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i); // 앞에 들어올 놈들
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		answer.push_back(cur);
		q.pop();

		for (int i = 0; i < Back[cur].size(); i++) {
			indegree[Back[cur][i]]--;
			if (indegree[Back[cur][i]] == 0) {
				q.push(Back[cur][i]);
			}
		}
	}

	return answer;
}
int main() {

	input();

	vector<int> answer = solution();
	if (answer.size() != n) {
		cout << 0;
		return 0;
	}
	for (auto i : answer) {
		cout << i << endl;
	}
	return 0;
}