#include <iostream>
#include <vector>
#include <deque>
#define endl "\n"
using namespace std;

int T, n;

int isTeam[100001]; // 1 : ������, -1 : �̹� ���� ����, 0 : ���� �˻���� 
vector<int> pick(100001);
deque<int> q;

void find_cycle(int Last) {
	bool isCycle = false;
	if (Last == -1) { // �̹� ���� ������ ������.
		while (!q.empty()) { 
			int cur = q.front();
			q.pop_front();
			isTeam[cur] = 1; // ���ݱ��� �˻��� ģ���� �湮ǥ��
		}
		return;
	}
	while (!q.empty()) { 
		int cur = q.front();
		q.pop_front();
		if (Last == cur) { // ����Ŭ�� ����� ���⼭���ʹ� ������ ����
			isCycle = true;
		}
		if (isCycle) {
			isTeam[cur] = -1;
		}
		else {
			isTeam[cur] = 1;
		}
	}
	return;
}

void search(int root, int next) {
	q.push_back(next);
	if (isTeam[next] == -1) { // ���� �ִ� ���
		q.pop_back(); // ���� �ִ� ģ���� ���� �������� �湮ǥ���Ϸ���
		find_cycle(-1);
		return;
	}
	if (isTeam[next] == 1) { // �湮���� �ִ� ���� ��� ����Ŭ �˻�
		q.pop_back(); // �̹� �湮�� ģ���� ���� �˻�����.
		find_cycle(next);
		return;
	}
	isTeam[next] = 1;
	search(root, pick[next]);
	return;
}

void solution() {
	for (int i = 1; i <= n; i++) {
		if (isTeam[i] == 0) { // ���� ���˻� X
			q.push_back(i);
			isTeam[i] = 1;
			search(i, pick[i]);
		}
	}
}
int main() {

	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	cin >> T;
	for(int i=0; i<T; i++) {
		fill(isTeam, isTeam + 100001, false);
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> pick[j];
		}
		solution();
		int answer = 0;
		for (int k = 1; k <= n; k++) {
			if (isTeam[k] == 1) answer++;
			// cout << isTeam[k] << " ";
		}
		cout << answer << endl;
	}
	

	return 0;
}