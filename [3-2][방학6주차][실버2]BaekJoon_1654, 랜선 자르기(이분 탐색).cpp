#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long k, n, size;
vector<long long> Line;

int main() {

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		long long num;
		cin >> num;
		Line.push_back(num);
	}

	sort(Line.begin(), Line.end());
	long long start = 0;
	long long end = Line.back();

	while (start <= end) {

		long long cnt = 0;
		long long Half_ = (start + end) / 2;
		if (Half_ == 0) Half_++;
		for (int i = 0; i < k; i++) {
			cnt += Line[i] / Half_;
		}

		if (cnt < n) {
			end = Half_ - 1;
		}
		else {
			start = Half_ + 1;
		}
		//cout << "Half : " << Half_ << endl;
	}

	cout << end;

	return 0;
}