// Merge k Sorted Lists
#include <iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		int k = 0;
		while (k < lists.size()) {//k arrays is NULL
			int min = 0x3fffffff;
			int mini = -1;
			k = 0;
			for (int i = 0; i < lists.size(); i++) {
				if (!lists[i])
					k++;
				if (lists[i] && lists[i]->val < min) {
					min = lists[i]->val;
					mini = i;
				}
			}
			if (mini != -1) {
				p->next = new ListNode(min);
				p = p->next;
				lists[mini] = lists[mini]->next;
			}
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