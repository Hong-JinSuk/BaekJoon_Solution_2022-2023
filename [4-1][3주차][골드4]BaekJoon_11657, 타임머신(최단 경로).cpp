#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"
#define INF 987654321
using namespace std;

vector<long long> R_C(501, INF); // 시작지점에서 도착지점으로 가는데 필요한 비용 초기화
vector<vector<int>> Route(501, vector<int>(501, INF)); // A->B 비용 초기화

int n, m, A, B, C;
bool isCycle;

void Search() { // 벨만-포드 알고리즘
	
	R_C[1] = 0;

	// 갈 수 있는 모든 경우의 수를 처리해준다.
	for (int k = 0; k < n; k++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				int cost = Route[start][end];
				if (R_C[start] == INF) continue;
				if (R_C[end] > (R_C[start] + cost)) R_C[end] = R_C[start] + cost;
			}
		}
	}

	// 한번 더 실행시 값이 변하면 음의 사이클이 존재한다.	
	for (int start = 1; start <= n; start++) {
		for (int end = 1; end <= n; end++) {
			int cost = Route[start][end];
			if (R_C[end] == INF) continue;
			if (R_C[end] > R_C[start] + cost) {
				// 값이 바뀌면 음의 사이클 존재
				isCycle = true;
				return;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> A >> B >> C;
		if (Route[A][B] > C) Route[A][B] = C; // 항상 제일 짧은 거리로 초기화
	}

	Search();

	if (isCycle) cout << -1;

	else {
		for (int i = 2; i <= n; i++) {
			cout << (R_C[i] == INF ? -1 : R_C[i]) << endl;
		}
	}

	return 0;
}