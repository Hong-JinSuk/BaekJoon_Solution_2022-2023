#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
int Min = 1000000001;

int main() {

	cin >> N;
	int* Arr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> Arr[i];
	}	

	sort(Arr, Arr + N);
	
	// 양 옆에서 줄이는 형식
	int Left = 0, Right = N - 1;

	//정답을 저장해둘 배열
	int ans[2];
	//ans[0] = Arr[Left];
	//ans[1] = Arr[Right];

	while (Left < Right) {

		int Sum = Arr[Left] + Arr[Right];

		// 0보다 Best는 없다.
		if (Sum == 0) {
			ans[0] = Arr[Left];
			ans[1] = Arr[Right];
			break;
		}

		// 합이 음수면
		else if (Sum < 0) {
			// 합의 절대값이 Min보다 작으면
			if (abs(Sum) < Min) {
				//Min을 바꿔주고 정답저장
				Min = abs(Sum);
				ans[0] = Arr[Left];
				ans[1] = Arr[Right];
			}
			// 음수를 줄여준다.
			Left++;
		}
		// 합이 양수면
		else {
			// 합의 절대값이 Min보다 작으면
			if (abs(Sum) < Min) {
				//Min을 바꿔주고 정답저장
				Min = abs(Sum);
				ans[0] = Arr[Left];
				ans[1] = Arr[Right];
			}
			// 양수를 줄여준다.
			Right--;
		}
	}

	cout << ans[0] << " " << ans[1];

	return 0;
}