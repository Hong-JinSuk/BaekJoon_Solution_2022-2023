#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"
#define MAX 9876543210
using ll = long long;
using namespace std;

int n, L;
vector<ll> A;
// ���� max(0,i-L+1), i�� ���ؼ� ���� �� �ּڰ� ���
void input() {
	cin >> n >> L;
	long long num;
	A.push_back(0); // index�� 1~5�鸸���� ������
	for (int i = 1; i <= n; i++) {
		cin >> num;
		A.push_back(num);
	}
}

void sol() {

	priority_queue<pair<ll, int>> q; // data, indexs
	for (int i = 1; i <= n; i++) {
		int Start = i - L + 1;
		if (Start <= 0) Start = 0; // Start>0 ���ʹ� ������ 1�� �ڸ���, �����ʿ� 1�� ���� 
		int cur = A[i];
		while (1) {
			if (q.empty() || cur < -q.top().first) { //ó�� or �̹��� �ּڰ��̸�
				q.push({ -A[i],i });
				break;
			}
			else if( q.top().second < Start ){ // �ּڰ��� ���� ���̸�
				q.pop();
			}
			else { // �ּڰ��� ���� ���̸� �׳� push
				q.push({ -A[i],i });
				break;
			}
		}
		cout << -q.top().first << " ";
		
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	input();
	sol();
	return 0;
}