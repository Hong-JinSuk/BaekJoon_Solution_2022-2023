#include<iostream>
#include<vector>
#include<queue>
#define MAX 987654231
using namespace std;

int n, m, w, TC; // ����, ����, ��Ȧ(���⤷)
int dp[2501];

void input(vector<pair<int, int>> Gate[2501]) {
	for (int i = 0; i < 1; i++) {
		cin >> n >> m >> w;
		int s, e, t;
		for (int j = 0; j < m; j++) { // ����
			cin >> s >> e >> t;
			Gate[s].push_back({ e,t });
			Gate[e].push_back({ s,t });
		}
		for (int j = 0; j < w; j++) { // ��Ȧ
			cin >> s >> e >> t;
			Gate[s].push_back({ e,-t });
		}
	}
}

//void Search(vector<pair<int, int>> Gate[2501]) {
//
//	for (int i = 1; i <= n; i++) { // ��� �����̵� ���� ����Ŭ �����ϸ� ��.
//
//		for (int k = 0; k < 2501; k++)
//			dp[k] = MAX;
//
//		queue<int> q;
//
//		int start = i;
//		dp[start] = 0; // ���������� �ʱ�ȭ
//		q.push(start);
//		int cnt = 0;
//		while (!q.empty()) {
//			int q_size = q.size();
//			cnt++;
//			for (int x = 0; x < q_size; x++) { // BFS���
//				int cur = q.front(); // ���� ��ġ
//				int cur_time = dp[cur];
//				q.pop();
//
//				for (int j = 0; j < Gate[cur].size(); j++) { // ���� ���������� ��
//					int next = Gate[cur][j].first;
//					int Time = Gate[cur][j].second;
//					if (dp[next] > dp[cur] + Time) { // �� �������̸�
//						q.push(next);
//						// ���� ���ε�, �̹� ���������� �ִ�?? => ���� ����Ŭ �˻�
//						if (dp[next] != MAX && dp[next] + dp[cur] + Time < 0) { 
//							//cout << dp[next] << ", " << dp[cur] + Time << endl;
//							cout << "YES\n";
//							return;
//						}
//						/*if (cnt == n - 1) {
//							cout << "YES\n";
//							return;
//						}*/
//						dp[next] = dp[cur] + Time; // ����
//					}
//				}
//			}
//		}
//	}
//	cout << "NO\n";
//	return;
//}

// ��Ȧ�� ���� ��, 1->2->3->4 ���Ŀ� 1->4 �� ��Ȧ�ΰ��� YES�� ����.

void Search(vector<pair<int,int>> Gate[2501]) {

	for (int k = 0; k < 2501; k++)
		dp[k] = 0;

	for (int i = 1; i < n; i++) { // n-1��
		for (int cur = 1; cur <= n; cur++) { // ��� ��������
			for (int k = 0; k < Gate[cur].size(); k++) { // ���� ����
				int next = Gate[cur][k].first;
				int cur_time = dp[cur];
				int Cost = Gate[cur][k].second;

				// ������ ��츸 update -> ���� ����Ŭ�̸� �ᱹ ������.
				if (dp[next] > cur_time + Cost) dp[next] = cur_time + Cost;
			}
		}
	}

	for (int cur = 1; cur <= n; cur++) { // ��� ��������
		for (int k = 0; k < Gate[cur].size(); k++) { // ���� ����
			int next = Gate[cur][k].first;
			int cur_time = dp[cur];
			int Cost = Gate[cur][k].second;

			// ������ ��츸 update -> ���� ����Ŭ�̸� �ᱹ ������.
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