#include<iostream>
#include<vector>
using namespace std;

int n;
bool isSame;
int compare;
//vector<vector<int>> v;
int v[2300][2300];
int answer_1 = 0, answer_2 = 0, answer_3 = 0;

void Check(int x) {
	if (x != compare) isSame = false;
	else isSame = true;
}

void div(int x, int y, int size) {
	isSame=true;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (v[i][j] != v[y][x]) {
				isSame = false;
				break;
			}
		}
		if (!isSame) break;
	}

	// 같지 않으면 9등분
	if (!isSame) {
		for (int i = 0; i < 3; i++) {
			int y_ = y + ((size / 3) * i);
			for (int j = 0; j < 3; j++) {
				int x_ = x + ((size / 3) * j);
				div(x_, y_, size / 3);
			}
		}
	}
	else {
		if (v[y][x] == -1) answer_1 += 1;
		else if (v[y][x] == 0)answer_2 += 1;
		else answer_3 += 1;
	}
}

int main() {

	cin >> n;
	
	//// n*n 배열 생성
	//for (int i = 0; i < n; i++) {
	//	vector<int> num(n);
	//	v.push_back(num);
	//}

	//// 데이터 삽입
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		int num;
	//		cin >> num;
	//		v[i][j] = num;
	//	}
	//}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	div(0, 0, n);

	cout << answer_1 << endl << answer_2 << endl << answer_3;

	return 0;
}