#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;

vector<int> Building[501]; // �������Ŀ��� ȭ��ǥ�� �����³��� �޴³��� ���ҷ� ����.
vector<int> Building_2[501]; // �׳� ������ �ִ´�� �޴� �Լ�
int Time[501]; // �ε����� ����µ� �ɸ��� �ð�
int indegree[501]; // �������Ŀ��� ���̴� ȭ��ǥ�� �޴� ����
int Buildtime[501]; // ���ݱ��� �������� �ɸ��� �ð�

void input() {
	cin >> n;
	int a, b;
	for (int i = 1; i <= n; i++) {
		cin >> Time[i]; // i���� �ǹ� ���µ� �ɸ��� �ð�
		while (cin >> a) {
			if (a == -1) break;
			Building_2[i].push_back(a);
			Building[a].push_back(i); // i�ǹ��� ����� a�ǹ��� ���� �� ����.
			indegree[i]++;
		}
	}

}

void solution() {
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0) q.push(i);

	while (!q.empty()) {
		int q_size = q.size();

		for (int i = 0; i < q_size; i++) {
			int cur = q.front();
			q.pop();

			Buildtime[cur] += Time[cur];

			for (int j = 0; j < Building[cur].size(); j++) {
				int next = Building[cur][j];
				indegree[next]--; // �ռ� �ǹ��� ����
				if (indegree[next] == 0) {
					q.push(next);
					int MAX = 0;
					for (auto a : Building_2[next]) {
						MAX = max(MAX, Buildtime[a]);	
					} // �Ʒ� ���ÿ��� 4��°�� 3,5�� �� ū���� ���󰡰���.
					//cout << MAX << endl;
					Buildtime[next] += MAX;
					// ���� �ڵ�� �ð� �Ű��� ����.
					//Buildtime[next] += Buildtime[cur];
				}
			}
		}
	}
}

// 5
// 10 - 1
// 20 1 - 1
// 30 2 - 1
// 40 3 5 - 1
// 100 - 1
// ��ó�� ������ �´µ�, �ð��� ���õ� ������ ����
// �������� dp�� �ƴϰ� �׸��� �����ε�??

int main() {

	input();
	solution();
	for (int i = 1; i <= n; i++) {
		cout << Buildtime[i] << endl;
	}

	return 0;
}