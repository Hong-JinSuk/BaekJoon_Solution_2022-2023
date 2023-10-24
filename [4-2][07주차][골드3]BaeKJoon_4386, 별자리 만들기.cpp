#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int n;
double x, y;
vector<pair<double, double>> Star;
priority_queue<pair<double, pair<int, int>>> q; // cost, start, end
int parent[101];
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		Star.push_back({ x,y });
		parent[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double x = Star[i].first - Star[j].first;
			double y = Star[i].second - Star[j].second;
			double Len = sqrt(pow(x, 2) + pow(y, 2)); // 두 점 사이의 거리
			Len = round(Len * 100) / 100;
			q.push({ -Len,{i+1,j+1} }); // 오름차순 저장
		}
	}
}

int find_p(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find_p(parent[x]);
}

void union_star(int x, int y) {
	int px = find_p(x);
	int py = find_p(y);

	if (px == py) return;
	else if (px > py) parent[px] = py;
	else parent[py] = px;
}

void sol() {
	double answer = 0;
	while (!q.empty()) {
		double cost = -q.top().first, Start = q.top().second.first, End = q.top().second.second;
		q.pop();
		if (find_p(Start) == find_p(End)) continue; // 연결되어 있으면 넘어감
		union_star(Start, End);
		answer += cost;
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	input();
	sol();
	return 0;
}