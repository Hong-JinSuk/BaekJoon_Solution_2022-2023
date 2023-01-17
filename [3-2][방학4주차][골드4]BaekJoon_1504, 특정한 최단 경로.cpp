#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

int N, E, v1, v2;
int Dist[888];
vector<pair<int, int>> node[888];
priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;

void Search(int start) {
	
	for (int i = 1; i < N + 1; i++) {
		Dist[i] = INF;
	}

	Dist[start] = 0;

	pq.push(make_pair(0, start));

	while (!pq.empty()) {

		int Sum = pq.top().first;
		int Current_node = pq.top().second;
		pq.pop();

		// 현재 노드에 붙어있는 간선의 갯수만큼 반복
		for (int i = 0; i < node[Current_node].size(); i++) {

			int next = node[Current_node][i].first;
			int cost = node[Current_node][i].second;

			if (cost + Sum < Dist[next]) {
				Dist[next] = cost + Sum;
				pq.push(make_pair(Dist[next], next));
			}
		}

	}

}

int main() {

	cin >> N >> E;

	for (int i = 0; i < E; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		// 양방향임
		node[u].push_back(make_pair(v, cost));
		node[v].push_back(make_pair(u, cost));
	}

	cin >> v1 >> v2;

	long long int _v1, v1_v2, v1_N, _v2, v2_v1, v2_N;

	Search(v1);
	_v1 = Dist[1]; // cost of 1_node to v1_node
	v1_v2 = Dist[v2];
	v1_N = Dist[N];

	Search(v2);

	_v2 = Dist[1];
	v2_v1 = Dist[v1];
	v2_N = Dist[N];

	long long int case1 = _v1 + v1_v2 + v2_N;  // 1->v1->v2->N
	long long int case2 = _v2 + v2_v1 + v1_N;  // 1->v2->v1->N

	//cout << "case 1: " << case1 << endl;
	//cout << "case 2: " << case2 << endl;

	long long int answer = case1 < case2 ? case1 : case2;
	
	if (answer >= INF || answer <= 0) cout << -1;
	else cout << answer;

	return 0;
}