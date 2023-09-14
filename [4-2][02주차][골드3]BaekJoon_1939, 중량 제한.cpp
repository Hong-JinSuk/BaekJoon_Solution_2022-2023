#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#define endl "\n"
using namespace std;

int n, m, Start, End;
int MAX = 0;
bool isvisit[100001];
vector<pair<int,int>> Road[100001];

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		Road[start].push_back({ end,cost });
		Road[end].push_back({ start,cost });

		MAX = cost > MAX ? cost : MAX;
	}
	cin >> Start >> End;
}

bool BFS(int test_cost) { // test cost가 가장 높은 것인지 직접 확인

	queue<int> q;
	q.push(Start);
	isvisit[Start] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		
		if (cur == End) return true;

		for (int i = 0; i < Road[cur].size(); i++) {
			int next = Road[cur][i].first;
			int cost = Road[cur][i].second;

			if (!isvisit[next] && cost >= test_cost) {
				isvisit[next] = true;
				q.push(next);
			}
		}
	}
	return false;
}

void solution() {
	int low = 0;
	int high = MAX;
	while (low <= high) {
		fill(isvisit, isvisit + 100001, false);
		int mid = (low + high) / 2;
		if (BFS(mid)) low = mid + 1; // mid가 된다면 더 큰 수들도 비교
		else high = mid - 1;
	}
	cout << high << endl;
}


int main() {

	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	input();
	solution();

	return 0;
}