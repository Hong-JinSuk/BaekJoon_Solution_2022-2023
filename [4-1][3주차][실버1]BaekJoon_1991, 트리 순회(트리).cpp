#include<iostream>
#include<vector>
using namespace std;

int n;
char left_c, right_c, root;

struct node {
	char left;
	char right;
};

vector<node> Tree(26);

void preOrder(char cur) {
	int Cur = cur - 'A';
	if (cur == '.') return;

	cout << cur;
	preOrder(Tree[Cur].left);
	preOrder(Tree[Cur].right);
}

void inOrder(char cur) {
	int Cur = cur - 'A';
	if (cur == '.') return;

	inOrder(Tree[Cur].left);
	cout << cur;
	inOrder(Tree[Cur].right);
}

void postOrder(char cur) {
	int Cur = cur - 'A';
	if (cur == '.') return;

	postOrder(Tree[Cur].left);
	postOrder(Tree[Cur].right);
	cout << cur;
}

int main() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> root >> left_c >> right_c;
		int Root = root - 'A';
		Tree[Root].left = left_c;
		Tree[Root].right = right_c;
	}

	preOrder('A');
	cout << endl;
	inOrder('A');
	cout << endl;
	postOrder('A');

	return 0;
}