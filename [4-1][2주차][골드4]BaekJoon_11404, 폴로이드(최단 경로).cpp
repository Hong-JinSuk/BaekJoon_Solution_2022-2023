#include<iostream>
#include<vector>
#include<queue>
#define endl "\n";
using namespace std;

int n, m, Start, End, Cost, Next;
vector<vector<int>> Route(101, vector<int>(101, 0));
int Move[101][101];

void Search() {

	queue<int> q;
	int visit_cost[101];

	// �������� n��
	for (int i = 1; i <= n; i++) {

		// ��� �ʱ�ȭ, �� �κ� 100001 ���� �س��µ�, �����غ��� 100000*100 ���� �Ǿ�� ���...
		for (int k = 0; k < 101; k++) {
			visit_cost[k] = 100000001;
		}

		// �����ϴ� ���� push
		q.push(i);

		// �� �ڵ带 while�� �ȿ��� visit_cost[cur]=0 ���� �س���,, �� �Լ� 0 ���� �̷�..
		visit_cost[i] = 0; // ���� ������ �׻� 0

		// q�� �������� ����
		while (!q.empty()) {

			int cur = q.front(); // ���� ����
			q.pop(); // ���� �޾ƿ����� pop

			for (int j = 1; j <= n; j++) { // ���� �������� �ٸ��������� ��� Ž��
				Next = j; // j�� ���� �������� �̵��� ����
				if (Route[cur][Next]) { // ���� �������� �̵��� ��ΰ� �ִٸ�
					int move_cost = visit_cost[cur] + Route[cur][Next]; // ���� ���������� ���+�̵��� ���
					if (move_cost < visit_cost[j]) { // move_cost�� ���ݱ����� visit_cost���� ���ٸ�
						q.push(Next); // ���� ������ �����ϴ� �������� �Ѵ�. 
						visit_cost[Next] = move_cost; // visit_cost ���� �ٲ��ش�.
					}
				}
			}
		} // ��� q ����Ϸ�

		for (int j = 1; j <= n; j++) {
			Move[i][j] = visit_cost[j];
		}
	}

}

int main() {

	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> Start >> End >> Cost;
		// ���� ��η� ���� ������ 2�� �̻��� ��, �� ���� ������ ���
		if (Route[Start][End]) Route[Start][End] = min(Route[Start][End], Cost);
		else Route[Start][End] = Cost;
	}

	Search();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (Move[i][j] == 100000001) cout << 0 << " "; // ���� ���°�� 0
			else cout << Move[i][j] << " ";
		}
		cout << endl;
	}
	

	return 0;
}