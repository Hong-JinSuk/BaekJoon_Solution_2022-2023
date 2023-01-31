#include<iostream>

using namespace std;

int a, b, c;

int div(int a, int b, int c) {
	if (b == 1) return a % c;
	else {
		long long temp = div(a, b / 2, c);
		if (b % 2) return (temp * temp) % c * a % c;
		else return (temp * temp) % c;
	}
}

int main() {

	cin >> a >> b >> c;

	cout << div(a,b,c);

	return 0;
}