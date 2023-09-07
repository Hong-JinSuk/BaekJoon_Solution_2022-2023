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
	for (int i = 1; i < n; i++) { // 첫번째집은 이미 설치함
		if (house[i] - start >= mid) { // 설치할 거리가 되면
			cnt++; //설치
			start = house[i]; // 여기서부터 다시 거리를 잰다.
		}
	}
	if (cnt >= c) return true; // 모두 설치했으면
	else return false; // 설치할 공간이 안나오는 mid라면
}

int sol() {
	int start = 0;
	int end = house.back();
	int answer = 0;
	while (start <= end) {
		int mid = start + (end - start) / 2; // 두 공유기의 가장 가까운거리
		if (Install(mid)) { // 설치할 수 있는 mid값이라면
			answer = max(answer, mid); // 가장큰 사이값을 찾는다.
			start = mid + 1; // 더 큰값 찾음
		}
		else end = mid - 1; // 더 작은값 찾음
	}
	return answer;
}

int main() {

	input();
	cout << sol();

	return 0;
}