#include<iostream>
#define endl "\n"
using namespace std;

struct Node {
	int data;
	Node* right;
	Node* left;
};

void postOrder(Node* node) {
	if (node->left != NULL) postOrder(node->left);
	if (node->right != NULL) postOrder(node->right);
	cout << node->data << endl;
}

Node* Insert(Node* node, int data) {
	if (node == NULL) {
		node = new Node();
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}
	else if (data <= node->data) node->left = Insert(node->left, data);
	else node->right = Insert(node->right, data);
	return node;
}

int main() {

	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	Node* root = NULL;
	int num;

	while (cin >> num) {
		if (num == EOF) break;
		root = Insert(root, num);
	}

	postOrder(root);

	return 0;
}