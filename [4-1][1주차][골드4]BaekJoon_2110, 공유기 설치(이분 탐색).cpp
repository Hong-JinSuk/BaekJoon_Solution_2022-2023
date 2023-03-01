#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, c, x;
vector<int> house;

// dis 의 거리로 설치를 하면 설치를 할 수 있나??
bool Install(int dis) {

	int cnt = 1, start = house[0];

	for (int i = 1; i < n; i++) {

		// 설치가 되는 거리면 설치하고 설치가 된 집에서 다시 시작.
		if (house[i] - start >= dis) {
			cnt++;
			start=house[i];
		}

	}

	// 설치가 되면 true 아니면 false 반환
	if (cnt >= c) return true;
	else return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> x;
		house.push_back(x);
	}

	sort(house.begin(), house.end());

	// 설치를 할 수 있는 최소, 최대 거리
	int Min = 1, Max = house[n - 1] - house[0];
	int ans = 0;


	while (Min <= Max) {

		// 이분 탐색
		int mid = (Min + Max) / 2;
		
		// mid가 설치할 수 있는 거리라면
		if (Install(mid)) {
			// ans 초기화 해주고
			ans = max(ans, mid);
			// 최소값을 두배로 올려서 올려서 다시해준다.
			Min = mid + 1;
		}
		// 설치할 수 없는 거리라면 최대값을 반으로 줄여서 다시 해준다.
		else Max = mid - 1;

	}

	cout << ans;

	return 0;
}