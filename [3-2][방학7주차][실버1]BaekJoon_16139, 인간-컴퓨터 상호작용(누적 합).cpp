#include<iostream>
using namespace std;

string s;
int q;
int wordSum[26][200006];


int main() {

	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL);

	cin >> s >> q;

	for (int i = 1; i < s.size() + 1; i++) {

		if (i > 1) {
			for (int j = 0; j < 26; j++) {
				wordSum[j][i] = wordSum[j][i - 1];
			}
		}
		int word = s[i-1] - 'a';
		wordSum[word][i]++;
		
	}


	while (q--) {

		char Word;
		int start, end;
		cin >> Word >> start >> end;
		int Search = Word - 'a';
		cout << wordSum[Search][end + 1] - wordSum[Search][start] << "\n"; // 이부분 endl로 하면 시간초과 남...
	}

	return 0;
}