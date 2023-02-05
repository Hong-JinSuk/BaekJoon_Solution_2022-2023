#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long int n, k, Size, Compare;
vector<long long int> Line;

void cutting(long long int DIV) {

	long long int cnt = 0;

	for (int i = 0; i < k; i++) {
		cnt += Line[i] / DIV;
	}

	if (cnt < n) {
		// type a
		if (DIV <= Compare) {
			Compare = DIV;
			cutting(DIV / 2);
		}
		// type c
		else {
			cutting((DIV + Compare) / 2);
		}
	}
	else if (cnt >= n) {
		// type b
		if (DIV != Compare) {
			long long int num = (Compare + DIV) / 2;
			if ((Compare + DIV) % 2) num++;
			Compare = DIV;
			cutting(num);
		}
		// type d
		else {
			Size = DIV;
			return;
		}
	}
}

int main() {

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		int len;
		cin >> len;
		Line.push_back(len);
	}


	sort(Line.begin(), Line.end());
	Compare = Line.back();

	cutting(Line.back());
	cout << Size;
	return 0;
}