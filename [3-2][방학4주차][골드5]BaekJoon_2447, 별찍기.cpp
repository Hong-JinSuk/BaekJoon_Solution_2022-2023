#include<iostream>

using namespace std;

int N;

void printStar(int len, int width, int num) {

	// N=3인경우 (1,1) 즉 가운데만 빈칸이기 때문이다.
	// N=9인경우 (3,{3,4,5}),(4,{3,4,5}),(5,{3,4,5}) 은 모두 3으로 나눌때, 몫이 1이다.
	// N=27인경우 9~17 x 9~17인데, 이 또한 9로 나눌 때, 몫이 1이다. 같은 규칙이다.
	if ((len / num) % 3 == 1 && (width / num) % 3 == 1) cout << ' ';
	
	// 결국 N=3인 경우로 오게 되어 있는데, 가운데가 빈 한칸은 위에서 공백처리했다.
	else {
		// 공백처리되는 칸 말고는 모두 *을 찍는다.
		if (num / 3 == 0) cout << "*";
		// 결국 이 재귀문 때문에, N=3형식으로 모두 귀결된다.
		else printStar(len, width, num / 3);
	}
}

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printStar(i, j, N);
		}
		cout << endl;
	}

	return 0;
}