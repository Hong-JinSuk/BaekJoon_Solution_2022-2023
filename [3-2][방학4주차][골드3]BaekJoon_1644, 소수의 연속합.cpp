#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
vector<int> Sosu;

int main() {

	cin >> N;

	vector<bool> Num(N + 1);
	Num[1] = true;

	for (int i = 2; i < sqrt(N) + 1; i++) {
		if (!Num[i]) {
			for (int j = i + i; j < N + 1; j += i) Num[j] = true;
		}
	}

	// 에라토스 테네스의 체를 이용해서 소수를 구함
	int sum = 0;
	Sosu.push_back(0);
	for (int i = 2; i < N + 1; i++) {
		// 소수들을 계속해서 더해서 넣어준다.
		if (!Num[i]) {
			sum += i;
			Sosu.push_back(sum);
		}
	}

	int Left = 0, Right = 0, answer = 0;

	while (Left <= Right && Right < Sosu.size()) {
		if (Sosu[Right] - Sosu[Left] < N) Right++;
		else if (Sosu[Right] - Sosu[Left] > N) Left++;
		// Right-Left = N
		else {
			answer++;
			Right++;
			Left++;
		}
	}

	cout << answer;

	return 0;
}

//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<cmath>
//
//using namespace std;
//
//int N;
//int answer = 0;
//vector<int> Sosu;
//
//int main() {
//
//	cin >> N;
//
//	vector<bool> Num(N + 1);
//	Num[1] = true;
//
//	for (int i = 2; i < sqrt(N) + 1; i++) {
//		if (!Num[i]) {
//			for (int j = i + i; j < N + 1; j += i) Num[j] = true;
//		}
//	}
//
//	// 에라토스 테네스의 체를 이용해서 소수를 구함
//	for (int i = 2; i < N + 1; i++) {
//		if (!Num[i]) {
//			Sosu.push_back(i);
//		}
//	}
//
//	// 자기자신이 소수면 1을 더해준다.
//	if (Sosu.back() == N) {
//		answer++;
//	}
//
//	// N/2 보다 작은 소수만 더해주면서 구하면 된다.
//	for (int i = 0; i < Sosu.size(); i++) {
//		if (Sosu[i] > (N / 2 + 1)) {
//			Sosu.erase(Sosu.begin() + i, Sosu.end());
//			break;
//		}
//	}
//
//	sort(Sosu.begin(), Sosu.end(), greater<int>());
//
//	// 더하는건 2개부터
//	int check = 2;
//	int sosu = 0;
//
//	while (check <= Sosu.size()) {
//
//		// check개를 더해준다.
//		for (int j = 0; j < Sosu.size() - check + 1; j++) {
//			for (int i = j; i < check + j; i++) {
//				sosu += Sosu[i];
//			}
//			if (sosu == N) {
//				answer++;
//			}
//			// 이미 N보다 합이 낮은데 더 낮춰도 N이 될 수는 없다.
//			if (sosu < N) {
//				sosu = 0;
//				break;
//			}
//			sosu = 0;
//		}
//
//		// 더하는 갯수를 한개 늘려준다.
//		check++;
//	}
//
//	cout << answer;
//
//	return 0;
//}