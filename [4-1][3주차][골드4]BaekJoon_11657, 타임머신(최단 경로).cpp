#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"
#define INF 987654321
using namespace std;

vector<long long> R_C(501, INF); // ������������ ������������ ���µ� �ʿ��� ��� �ʱ�ȭ
vector<vector<int>> Route(501, vector<int>(501, INF)); // A->B ��� �ʱ�ȭ

int n, m, A, B, C;
bool isCycle;

void Search() { // ����-���� �˰���
	
	R_C[1] = 0;

	// �� �� �ִ� ��� ����� ���� ó�����ش�.
	for (int k = 0; k < n; k++) {
		for (int start = 1; start <= n; start++) {
			for (int end = 1; end <= n; end++) {
				int cost = Route[start][end];
				if (R_C[start] == INF) continue;
				if (R_C[end] > (R_C[start] + cost)) R_C[end] = R_C[start] + cost;
			}
		}
	}

	// �ѹ� �� ����� ���� ���ϸ� ���� ����Ŭ�� �����Ѵ�.	
	for (int start = 1; start <= n; start++) {
		for (int end = 1; end <= n; end++) {
			int cost = Route[start][end];
			if (R_C[end] == INF) continue;
			if (R_C[end] > R_C[start] + cost) {
				// ���� �ٲ�� ���� ����Ŭ ����
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
		if (Route[A][B] > C) Route[A][B] = C; // �׻� ���� ª�� �Ÿ��� �ʱ�ȭ
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