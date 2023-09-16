#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, k, m, v, c;
vector<pair<int, int>> jewel;
priority_queue<int, vector<int>, greater<int>> bag;

// n : ������, m : ����, v : ����, k : ����, c : ���� �� �ִ� ����
void input() {

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> m >> v;
		jewel.push_back({ m,v });
	}

	sort(jewel.begin(), jewel.end());

	for (int i = 0; i < k; i++) {
		cin >> c;
		bag.push(c);
	}
	return;
}

// �Ƴ��̰� int�� �س��� ���� �����ɷȳ�...
long long solution() { 
	long long answer = 0;

	priority_queue<int, vector<int>, less<int>> price;
	int index = 0; // Ž���� ���� ����

	while (!bag.empty()) { // ��� �賶 Ž��
		int cur_bag = bag.top();
		//cout << "Bag : " << cur << endl;
		bag.pop();
		// ���� �賶���� ���� �� �ִ� ��� ���� Ž��
		while (index<jewel.size()) { 
			// ���� �������� �� ���� �� ������ break
			if (cur_bag < jewel[index].first) break;
			// ���� �������� ������ ���� �� ������ �� ��ġ�� ����
			else if (cur_bag >= jewel[index].first) {
				//cout << "push price : " << jewel[index].second << endl;
				price.push(jewel[index].second);
				index++; // �������� ����
			}
		}
		if (!price.empty()) { // ���� �� �ִ� ������ �ִٸ�
			//cout << "answer += " << price.top() << endl;
			answer += price.top(); // ���� ���� ��Ѱ� ��´�.
			price.pop();
		}
	}
	return answer;
}

int main() {

	input();
	cout << solution();

	return 0;
}