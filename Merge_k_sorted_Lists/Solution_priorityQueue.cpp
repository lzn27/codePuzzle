// Merge k Sorted Lists
#include <iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
	bool operator()(ListNode *p1, ListNode *p2) {
		return p1->val >= p2->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*,vector<ListNode*>,cmp> que;
		for (int i = 0; i < lists.size(); i++) {
			if(lists[i])
				que.push(lists[i]);
		}
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		while (que.size()) {
			ListNode *temp = que.top();
			que.pop();
			if (temp->next)
				que.push(temp->next);
			p->next = new ListNode(temp->val);
			p = p->next;
		}
		p = head->next;
		delete(head);
		return p;
	}
};

ListNode* buildList() {
	ListNode *head = new ListNode(0);
	ListNode *p = head;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		p->next = new ListNode(temp);
		p = p->next;
	}
	p = head->next;
	delete(head);
	return p;
}

int main() {
	Solution solu;
	vector<ListNode*> vec;
	ListNode *p1 = buildList();
	ListNode *p2 = buildList();
	vec.push_back(p1);
	vec.push_back(p2);
	ListNode* res = solu.mergeKLists(vec);
	while (res) {
		cout << res->val << ' ';
		res = res->next;
	}
	return 0;
}