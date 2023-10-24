#include<iostream>
#include<vector>
#include<queue>
#define endl "\n"
#define MAX 9876543210
using ll = long long;
using namespace std;

int n, L;
vector<ll> A;
// 범위 max(0,i-L+1), i에 대해서 범위 내 최솟값 출력
void input() {
	cin >> n >> L;
	long long num;
	A.push_back(0); // index를 1~5백만으로 쓸려고
	for (int i = 1; i <= n; i++) {
		cin >> num;
		A.push_back(num);
	}
}

void sol() {

	priority_queue<pair<ll, int>> q; // data, indexs
	for (int i = 1; i <= n; i++) {
		int Start = i - L + 1;
		if (Start <= 0) Start = 0; // Start>0 부터는 왼쪽은 1개 자르고, 오른쪽에 1개 붙힘 
		int cur = A[i];
		while (1) {
			if (q.empty() || cur < -q.top().first) { //처음 or 이번게 최솟값이면
				q.push({ -A[i],i });
				break;
			}
			else if( q.top().second < Start ){ // 최솟값이 범위 밖이면
				q.pop();
			}
			else { // 최솟값이 범위 안이면 그냥 push
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