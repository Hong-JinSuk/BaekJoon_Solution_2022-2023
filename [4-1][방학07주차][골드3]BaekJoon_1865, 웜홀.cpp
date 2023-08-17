#include<iostream>
#include<vector>
#include<queue>
#define MAX 987654231
using namespace std;

int n, m, w, TC; // 지점, 도로, 웜홀(방향ㅇ)
int dp[2501];

void input(vector<pair<int, int>> Gate[2501]) {
	for (int i = 0; i < 1; i++) {
		cin >> n >> m >> w;
		int s, e, t;
		for (int j = 0; j < m; j++) { // 도로
			cin >> s >> e >> t;
			Gate[s].push_back({ e,t });
			Gate[e].push_back({ s,t });
		}
		for (int j = 0; j < w; j++) { // 웜홀
			cin >> s >> e >> t;
			Gate[s].push_back({ e,-t });
		}
	}
}

//void Search(vector<pair<int, int>> Gate[2501]) {
//
//	for (int i = 1; i <= n; i++) { // 어느 지점이든 음의 사이클 존재하면 됌.
//
//		for (int k = 0; k < 2501; k++)
//			dp[k] = MAX;
//
//		queue<int> q;
//
//		int start = i;
//		dp[start] = 0; // 시작지점은 초기화
//		q.push(start);
//		int cnt = 0;
//		while (!q.empty()) {
//			int q_size = q.size();
//			cnt++;
//			for (int x = 0; x < q_size; x++) { // BFS방식
//				int cur = q.front(); // 현재 위치
//				int cur_time = dp[cur];
//				q.pop();
//
//				for (int j = 0; j < Gate[cur].size(); j++) { // 현재 지점에서의 길
//					int next = Gate[cur][j].first;
//					int Time = Gate[cur][j].second;
//					if (dp[next] > dp[cur] + Time) { // 더 빠른길이면
//						q.push(next);
//						// 음의 길인데, 이미 지나온적이 있다?? => 음의 사이클 검사
//						if (dp[next] != MAX && dp[next] + dp[cur] + Time < 0) { 
//							//cout << dp[next] << ", " << dp[cur] + Time << endl;
//							cout << "YES\n";
//							return;
//						}
//						/*if (cnt == n - 1) {
//							cout << "YES\n";
//							return;
//						}*/
//						dp[next] = dp[cur] + Time; // 업뎃
//					}
//				}
//			}
//		}
//	}
//	cout << "NO\n";
//	return;
//}

// 웜홀만 있을 때, 1->2->3->4 이후에 1->4 로 웜홀로가면 YES가 나옴.

void Search(vector<pair<int,int>> Gate[2501]) {

	for (int k = 0; k < 2501; k++)
		dp[k] = 0;

	for (int i = 1; i < n; i++) { // n-1번
		for (int cur = 1; cur <= n; cur++) { // 모든 지점에서
			for (int k = 0; k < Gate[cur].size(); k++) { // 모든길 업뎃
				int next = Gate[cur][k].first;
				int cur_time = dp[cur];
				int Cost = Gate[cur][k].second;

				// 음수인 경우만 update -> 음의 싸이클이면 결국 업뎃됌.
				if (dp[next] > cur_time + Cost) dp[next] = cur_time + Cost;
			}
		}
	}

	for (int cur = 1; cur <= n; cur++) { // 모든 지점에서
		for (int k = 0; k < Gate[cur].size(); k++) { // 모든길 업뎃
			int next = Gate[cur][k].first;
			int cur_time = dp[cur];
			int Cost = Gate[cur][k].second;

			// 음수인 경우만 update -> 음의 싸이클이면 결국 업뎃됌.
			if (dp[next] > cur_time + Cost) {
				cout << "YES\n";
				return;
			}
		}
	}
	cout << "NO\n";
	return;
}

int main() {

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		vector<pair<int, int>> Gate[2501];	
		input(Gate);
		Search(Gate);
	}
	return 0;
}