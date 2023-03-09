#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> arr;
int main() {

	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	int Max = arr[0];
	int value = arr[0];

	for (int i = 1; i < n; i++) {
		value = max(arr[i], value + arr[i]);
		Max = max(Max, value);
	}

	cout << Max;

	return 0;
}