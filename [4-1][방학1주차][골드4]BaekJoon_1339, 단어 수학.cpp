#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define endl "\n"
using namespace std;

int n;
int alphabet[26];
string str;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j<str.size(); j++) {
			int index = str[j] - 'A';
			alphabet[index] += pow(10, str.size() - 1 - j);
		}
	}

	sort(alphabet, alphabet + 26, greater<int>());

	int answer = 0;

	for (int i = 0; i < 10; i++) {
		answer += alphabet[i] * (9 - i);
	}

	cout << answer;
	return 0;
}