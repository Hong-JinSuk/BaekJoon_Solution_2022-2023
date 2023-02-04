#include<iostream>
#include<map>
#include<vector>
#define MOD 1000000007
//#define MAX 1000000000000000000
using namespace std;

long long n;
map<long long, long long> m;

//vector<long long> v2(MAX);
//vector<pair<long long, long long>> v;

long long fibo(long long n) {

	if (n == 1) return 1;
	if (n == 2) return 1;
	if (m.count(n) > 0) return m[n];
	//if (v[n].first) return v[n].second;
	//if (v2[n]) return v2[n];
	if (n % 2 == 0) {
		long long x = n / 2;
		long long temp1 = fibo(x - 1), temp2 = fibo(x);
		m[n] = ((2LL * temp1 + temp2) * temp2) % MOD;
		//v2.insert(v[n].second , (2LL * temp1 + temp2) * temp2 % MOD);
		return m[n];
	}

	else {
		long long x = (n + 1) / 2;
		long long temp1 = fibo(x - 1), temp2 = fibo(x);
		m[n] = (temp1 * temp1 + temp2 * temp2) % MOD;
		//v.insert(v[n].second, (temp1 * temp1 + temp2 * temp2) % MOD);
		return m[n];
	}

}

int main() {

	cin >> n;

	cout << fibo(n);

	return 0;
}