#include<iostream>
#include<cmath>
using namespace std;

int n, k;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	// B[k]는 k보다 작거나 같으므로 Max=k로 설정했다.
	int Min = 1, Max = k;
	int ans = 0;

	while (Min <= Max) {

		// Find = 내가 찾을려는 수 (답)
		int Find = (Min + Max) / 2;
		int cnt = 0;

		// i*j / i = j다. 따라서 cnt는 내가 찾을려는 숫자보다
		// 작거나 같은 숫자들의 갯수가 된다.
		// https://kbw1101.tistory.com/29 알고리즘 설명 참고함.
		for (int i = 1; i <= n; i++) {
			cnt += min(n, Find / i);
		}

		// 만약 갯수가 많다면, 내가 찾을려는 수는 실제 답보다
		// 큰 것이므로 줄여준다.
		if (cnt >= k) {
			ans = Find;
			Max = Find - 1;
		}
		else Min = Find + 1;

	}

	cout << ans;

}