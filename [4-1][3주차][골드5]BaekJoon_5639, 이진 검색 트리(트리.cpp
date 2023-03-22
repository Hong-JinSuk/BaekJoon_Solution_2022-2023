//#include<iostream>
//#define endl "\n"
//#include<vector>
//using namespace std;
//
//struct node {
//	int right;
//	int left;
//};
//
//int num, root, l, r;
//vector<node> Tree;
//
//void postOrder(int cur) {
//	if (Tree[cur].left) postOrder(Tree[cur].left);
//	if (Tree[cur].right) postOrder(Tree[cur].right);
//	cout << cur << endl;
//}
//
//void makeTree(int cur) {
//	if (num < cur) {
//		if (Tree[cur].left == 0) {
//			Tree[cur].left = num;
//			//cout << cur << "'s left is " << num << endl;
//			return;
//		}
//		makeTree(Tree[cur].left);
//	}
//	if (num > cur) {
//		if (Tree[cur].right == 0) {
//			Tree[cur].right = num;
//			//cout << cur << "'s right is " << num << endl;
//			return;
//		}
//		makeTree(Tree[cur].right);
//	}
//}
//
//int main() {
//
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//
//	cin >> num;
//	int Root = num;
//
//	while (cin>>num) {
//		if (num == EOF) break;
//		makeTree(Root);
//	}
//	
//	postOrder(Root);
//
//	return 0;
//}

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