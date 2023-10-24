#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n;
vector<int> Next_do[10001]; // �� �۾��� ������ ������谡 ������ �͵�
int isCan[10001]; // �����ؾߵ� �۾� ����
int Time[10001];
void input() {
	cin >> n;
	int cnt;
	for (int i = 1; i <= n; i++) {
		cin >> Time[i]; // �� �۾��� �ϴµ� �ɸ��� �ð�
		cin >> cnt; // �����ؾߵ� �۾� ����
		isCan[i] = cnt;
		while (cnt--) {
			int do_first;
			cin >> do_first;
			Next_do[do_first].push_back(i); // do_first�� ������ ���� �Է����� �۾� ���� ���� �ؼ�
		}
	}
}

void sol() {
	int answer = 0;
	priority_queue<pair<int,int>> q_1; // �۾��ð�, �۾� ��ȣ
	priority_queue<pair<int,int>> q_2;

	for (int i = 1; i <= n; i++) {
		if (isCan[i] == 0)
			q_1.push({-Time[i], i}); // ���� ������ �� �ִ� �۾��� �����.
	}
	while (!q_1.empty() || !q_2.empty()) { // �� �迭�� ��� ��������
		int Min = 0;
		if (q_1.empty()) {
			Min = -q_2.top().first;
			while (!q_2.empty()) {
				int cost = -q_2.top().first-Min, index = q_2.top().second; q_2.pop();
				if (cost > 0) q_1.push({ -cost,index });
				else {
					for (int i = 0; i < Next_do[index].size(); i++) { // ���� �۾��� ����
						int End_ = Next_do[index][i]; // �� �۾��� ������ �����۾��� �ذ�Ǵ� �۾�
						isCan[End_]--;
						if (isCan[End_] == 0) { // �����۾��� ��� �Ϸ�Ǹ�
							q_1.push({ -Time[End_], End_ });
						}
					}
				}
			}
		}
		else if (q_2.empty()) {
			Min = -q_1.top().first;
			while (!q_1.empty()) {
				int cost = -q_1.top().first - Min, index = q_1.top().second; q_1.pop();
				if (cost > 0) q_2.push({ -cost,index });
				else {
					for (int i = 0; i < Next_do[index].size(); i++) { // ���� �۾��� ����
						int End_ = Next_do[index][i]; // �� �۾��� ������ �����۾��� �ذ�Ǵ� �۾�
						isCan[End_]--;
						if (isCan[End_] == 0) { // �����۾��� ��� �Ϸ�Ǹ�
							q_2.push({ -Time[End_], End_ });
						}
					}
				}
			}
		}
		cout << Min << endl;
		answer += Min;
	}
	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	input();
	sol();

	return 0;
}