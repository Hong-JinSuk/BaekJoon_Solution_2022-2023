#include<iostream>
#include<vector>
#define endl "\n"

using namespace std;

int n, m;
int answer = 0;
int cnt = 0;
vector<pair<int,int>> c[1001]; // 길이 저장되있음
int parent[100001]; // 실제로 연결된 집

int findParent(int root) {
	if (root == parent[root]) return root;
	else return parent[root] = findParent(parent[root]);
}

void unions(int a, int b, int cost) {
	//cout << a << ", " << b << endl;
	a = findParent(a);
	b = findParent(b);

	if (a != b) {
		parent[a] = b; // 연결된게 아니면 연결
		//cout << "cost : " << cost << endl;
		answer += cost;
		//cout << "a<->b" << endl;
		cnt++;
	}
}

void concat() {
	if (n == 2) return;
	for (int cost = 1; cost < 1001; cost++) {
		if (c[cost].empty()) continue;
		for (auto x : c[cost]) {
			int a = x.first;
			int b = x.second;
			unions(a, b, cost);
			if (cnt == n - 2) return;
		}
	}
}

int main() {

	cin >> n >> m;
	for (int i = 1; i < 100001; i++) {
		parent[i] = i; // 자기자신으로 초기화 ( 연결안되있음 )
	}

	for (int i = 0; i < m; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		c[cost].push_back({ a,b });
	}

	concat();

	cout << answer;

	return 0;
}