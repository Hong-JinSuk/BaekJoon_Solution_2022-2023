#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

int T, n, m;
vector<int> A(1001);
vector<int> B(1001);

void input() {
	cin >> T >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> B[i];
}

void make_sum(vector<int>& AS, vector<int>& BS) {
	for (int i = 0; i < n; i++) {
		int A_Sum = A[i];
		AS.push_back(A_Sum);
		for (int j = i + 1; j < n; j++) {
			A_Sum += A[j];
			AS.push_back(A_Sum);
		}
	}
	for (int i = 0; i < m; i++) {
		int B_Sum = B[i];
		BS.push_back(B_Sum);
		for (int j = i + 1; j < m; j++) {
			B_Sum += B[j];
			BS.push_back(B_Sum);
		}
	}
	sort(AS.begin(), AS.end());
	sort(BS.begin(), BS.end());
}

long long sol() {
	long long count = 0;

	vector<int> AS;
	vector<int> BS;
	make_sum(AS, BS);

	for (int i = 0; i < AS.size(); i++) {
		int answer = T - AS[i];
		int B_answer_down = lower_bound(BS.begin(), BS.end(), answer) - BS.begin();
		int B_answer_up = upper_bound(BS.begin(), BS.end(), answer) - BS.begin();
		count += B_answer_up - B_answer_down;
	}
	return count;
}

int main() {
	input();
	cout << sol();
	return 0;
}