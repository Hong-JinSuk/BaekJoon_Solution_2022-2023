#include<iostream>
#include<vector>

using namespace std;

vector<pair<int,int>> Road[100001];

bool isvisit[100001];
bool isUpdate = false;

long long MAX = 0;
int Start = 2;
int v;

void input() {

	cin >> v;
	for (int i = 0; i < v; i++) {
		int start, end, cost;
		cin >> start;
		while (1) {
			cin >> end;
			if (end == -1) break;
			cin >> cost;
			Road[start].push_back({ end,cost });
		}
	}
	return;
}

void dfs(int cur, long long Len) {
	isvisit[cur] = true;
	cout << "cur : " << cur << endl;
	for (int i = 0; i < Road[cur].size(); i++) {
		int next = Road[cur][i].first;
		int cost = Road[cur][i].second;
		if (!isvisit[next]) {
			dfs(next, Len + cost);
			isvisit[next] = false;
		}
	}
	
	if (MAX < Len) { // 가장 먼 곳이면 업데이트
		cout << "len : " << Len << endl;
		MAX = Len;
		Start = cur; // 여기가 시작지점에서 가장 먼곳임.
		isUpdate = true;
	}
	return;
}

void solution() {
	do {
		for (int i = 1; i <= v; i++) {
			isvisit[i] = false;
		}
		isUpdate = false;
		dfs(Start, 0);
	} while (isUpdate);
}

int main() {
	
	input();
	solution();
	cout << MAX;


	return 0;
}