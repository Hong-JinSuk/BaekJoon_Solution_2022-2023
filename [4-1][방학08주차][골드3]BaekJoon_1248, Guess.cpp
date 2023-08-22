#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
char Matrix[11][11];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <=n ; j++) {
			cin >> Matrix[i][j];
		}
	}
}

bool isRight(int index, int val, vector<int> answer) {
	answer[index] = val;
	int temp = 0;
	for (int i = index; i >= 1; i--) {
		temp += answer[i];
		if (Matrix[i][index] == '+' && temp <= 0) return false;
		if (Matrix[i][index] == '-' && temp >= 0) return false;
		if (Matrix[i][index] == '0' && temp != 0) return false;
	}
	return true;
}

void push(int index, vector<int>& answer) {
	if (index == n + 1) {
		for (int i = 1; i <= n; i++)
			cout << answer[i] << " ";
		exit(0);
	}
	for (int j = 1; j <= 10; j++) { // -1~10±îÁö ³Ö¾îº½
		if (Matrix[index][index] == '0') {
			answer[index] = 0;
			push(index + 1, answer);
		}
		else if (Matrix[index][index] == '+') {
			if (isRight(index, j, answer)) {
				answer[index] = j;
				push(index + 1, answer);
			}
		}
		else if (Matrix[index][index] == '-') {
			if (isRight(index, -j, answer)) {
				answer[index] = -j;
				push(index + 1, answer);
			}
		}
	}
	return;
}

//void push(int index, vector<int>& answer) {
//	
//	if (index == n + 1) {
//		for (int i = 1; i <= n; i++)
//			cout << answer[i] << " ";
//		exit(0);
//	}
//	for (int i = -10; i <= 10; i++) {
//		if (isRight(index, i, answer)) {
//			answer[index] = i;
//			push(index + 1, answer);
//		}
//	}
//}

void solution() {
	vector<int> answer(n + 1);

	push(1, answer);

	return;
}

int main() {
	input();
	solution();
}