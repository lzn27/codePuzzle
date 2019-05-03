//1130 Infix Expression 
//PTA Advanced Level
#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

struct Node {
	string data;
	int left;
	int right;
	Node(string s,int l,int r):data(s),left(l),right(r){}
};


class Solution {
public:
	void printExpression(vector<Node> tree,int root) {
		if (!(tree[root].left == -1 && tree[root].right == -1) && root != tree[0].left)
			cout << '(';
		if (tree[root].left != -1)
			printExpression(tree, tree[root].left);
		cout << tree[root].data;
		if (tree[root].right != -1)
			printExpression(tree, tree[root].right);
		if (!(tree[root].left == -1 && tree[root].right == -1) && root != tree[0].left)
			cout << ')';
	}
	vector<Node>* buildTree() {
		int n;
		cin >> n;
		vector<Node>* tree=new vector<Node>;
		bool isRoot[21];
		fill(isRoot, isRoot + 21, true);
		tree->push_back(Node("", 0, 0));
		while (n--) {
			string data;
			int l;
			int r;
			cin >> data >> l >> r;
			tree->push_back(Node(data, l, r));
			if (l != -1)isRoot[l] = false;
			if (r != -1)isRoot[r] = false;
		}
		int root;
		for (int i = 1; i < 21; i++) {
			if (isRoot[i]) {
				root = i;
				i = 21;
			}
		}
		(*tree)[0].left = root;
		return tree;
	}
};

int main() {
	Solution solu;
	vector<Node>* tree=solu.buildTree();
	solu.printExpression(*tree, (*tree)[0].left);
	return 0;
}