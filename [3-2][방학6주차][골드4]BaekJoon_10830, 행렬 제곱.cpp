#include<iostream>

using namespace std;

long long n, b;
int A[5][5];
int answer[5][5];

void Muti(int answer[][5], int A[][5]) {
	
	int temp[5][5] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				temp[i][j] += (answer[i][k] * A[k][j]);
			}
			temp[i][j] %= 1000;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer[i][j] = temp[i][j];
		}
	}
}

int main() {

	cin >> n >> b;

	// Input
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
		answer[i][i] = 1;
	}  
	
	while (b>0) {
		if (b % 2) {
			Muti(answer, A);
			//cout << "m answer\n";
		}
		Muti(A, A);
		b /= 2;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << answer[i][j] << ' ';
		cout << endl;
	}

	return 0;
}