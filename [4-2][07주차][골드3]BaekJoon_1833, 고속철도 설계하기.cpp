#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"
using namespace std;

int n;
int price = 0, cnt = 0;
int parent[201];
vector<int> road[201]; // index에서 가는 길
priority_queue<pair<int, pair<int, int>>> q; // cost, start, end
int find_p(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find_p(parent[x]);
}

void union_city(int x, int y) {
	int px = find_p(x);
	int py = find_p(y);
	if (px == py) return;
	if (px > py) {
		parent[px] = py;
	}
	else {
		parent[py] = px;
	}
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			road[i].push_back(num);
			if (num < 0) {
				price -= num;
				union_city(i, j);
			}
			if (num > 0) {
				q.push({ -num,{i,j} });
			}
		}
	}
	price /= 2;
}

void mst() {
	vector<pair<int, int>> ans;

	while (!q.empty()) {
		auto cur = q.top(); q.pop();
		int cost = -cur.first, Start = cur.second.first, End = cur.second.second;
		int ps = find_p(Start), pe = find_p(End);
		if (ps == pe) continue;
		ans.push_back({ Start,End });
		union_city(Start, End);
		cnt++;
		price += cost;
	}
	cout << price << " " << cnt << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << endl;

}
int main() {
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	input();
	mst();
	return 0;
}