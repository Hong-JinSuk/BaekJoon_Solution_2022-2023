//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#define MAX 30001
#define endl "\n"
using namespace std;

int n, m, k;
int Candy[MAX];
int Parent[MAX];
int Child[MAX];
int dp[3001];
vector<pair<int, int>> cluster;
int find_parent(int x) {
	if (Parent[x] == x) return x;
	return Parent[x] = find_parent(Parent[x]);
}

void union_friend(int x, int y) {
	int px = find_parent(x);
	int py = find_parent(y);
	if (px == py) return;
	if (px > py) {
		Parent[px] = py;
		Candy[py] += Candy[px]; // 化变 牡叼 葛滴 历厘
		Child[py] += Child[px]; // 化变 模备甸 葛滴 历厘
		return;
	}
	else {
		Parent[py] = px;
		Candy[px] += Candy[py];
		Child[px] += Child[py];
		return;
	}
}

void input() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		Parent[i] = i;
		Child[i] = 1;
	}
	for (int i = 1; i <= n; i++)
		cin >> Candy[i];
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		union_friend(x, y);
	}
	return;
}

int solution() {
	for (int i = 1; i <= n; i++) {
		if (Parent[i] == i) {
			cluster.push_back({ Candy[i],Child[i] });
		}
	}
	for (int i = 0; i < cluster.size(); i++) {
		int child_ = cluster[i].second;
		int candy_ = cluster[i].first;
		for (int j = k-1; j > 0; j--) {
			if (j - child_ >= 0) {
				dp[j] = max(dp[j], dp[j - child_] + candy_);
			}
		}
	}
	return dp[k - 1];
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	input();
	cout << solution();
	
	return 0;
}