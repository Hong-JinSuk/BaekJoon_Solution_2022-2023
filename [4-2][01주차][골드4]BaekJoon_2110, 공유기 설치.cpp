#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

int n, c;
vector<ll> house;

void input() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		house.push_back(x);
	}
	sort(house.begin(), house.end());
}

bool Install(int mid) {
	int cnt = 1;
	int start = house[0];
	for (int i = 1; i < n; i++) { // ù��°���� �̹� ��ġ��
		if (house[i] - start >= mid) { // ��ġ�� �Ÿ��� �Ǹ�
			cnt++; //��ġ
			start = house[i]; // ���⼭���� �ٽ� �Ÿ��� ���.
		}
	}
	if (cnt >= c) return true; // ��� ��ġ������
	else return false; // ��ġ�� ������ �ȳ����� mid���
}

int sol() {
	int start = 0;
	int end = house.back();
	int answer = 0;
	while (start <= end) {
		int mid = start + (end - start) / 2; // �� �������� ���� �����Ÿ�
		if (Install(mid)) { // ��ġ�� �� �ִ� mid���̶��
			answer = max(answer, mid); // ����ū ���̰��� ã�´�.
			start = mid + 1; // �� ū�� ã��
		}
		else end = mid - 1; // �� ������ ã��
	}
	return answer;
}

int main() {

	input();
	cout << sol();

	return 0;
}