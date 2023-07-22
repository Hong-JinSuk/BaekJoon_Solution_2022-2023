#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int solution(vector<int> know, vector<int> Party[], int m) {

	int answer = m;
	bool isEnd = false;

	while (!isEnd) {
		isEnd = true;
		for (int i = 0; i < m; i++) {

			if (Party[i].empty()) continue;
			for (int k = 0; k < know.size(); k++) {

				auto ex = find(Party[i].begin(), Party[i].end(), know[k]);
				if (ex != Party[i].end()) {

					for (int x = 0; x < Party[i].size(); x++) {
						
						// �ߺ��� ���Ұ� �ƴ� ��, push_back
						if (find(know.begin(), know.end(), Party[i][x]) == know.end()) {
							know.push_back(Party[i][x]);
							isEnd = false; // ���Ұ� �߰��Ǹ� �� ����
						}
					}
					answer--; // �ڶ��� ��Ƽ�� �پ�� ��
					Party[i].erase(Party[i].begin(), Party[i].end()); // �پ�� ��Ƽ ����
					break; // ��� �־������� ���� ��Ƽ��
				}
			}
		}
	}

	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, su;
	cin >> n >> m >> su;

	vector<int> Know;
	for (int i = 0; i < su; i++) {
		int num;
		cin >> num;
		Know.push_back(num);
	}

	vector<int> Party[50];
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int person;
			cin >> person;
			Party[i].push_back(person);
		}
	}

	cout << solution(Know, Party, m);

	return 0;
}