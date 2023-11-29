#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
int Weight[101];
int indegree[101];

bool zz[101];

vector<pair<int, int>> pro[101];

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int y, x, cnt;
		cin >> y >> x >> cnt;
		pro[y].push_back({ x,cnt });
		zz[y] = true; // 기본부품 아닌것들 표시
		indegree[x]++;
	}
}

void sol() {
	
	queue<int> q;
	q.push(n);
	Weight[n] = 1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < pro[cur].size(); i++) {
			int Part = pro[cur][i].first, Cnt = pro[cur][i].second;
			indegree[Part]--;
			Weight[Part] += Cnt * Weight[cur];
			if (indegree[Part] == 0) {
				q.push(Part);
			}
		}
	}

}

int main() {

	input();
	sol();

	for (int i = 1; i < n; i++) {
		if (!zz[i]) cout << i << " " << Weight[i] << endl;
	}
	return 0;
}