// Merge Two Sorted Lists（leetcode_easy）
#include <iostream>
#include<algorithm>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *p1 = l1, *p2 = l2;
		ListNode *head = new ListNode(0);
		ListNode *p = head;
		while (p1 != NULL || p2 != NULL) {
			if (p1 != NULL && p2 != NULL) {
				if (p1->val >= p2->val) {
					p->next = new ListNode(p2->val);
					p2 = p2->next;
					p = p->next;
				}
				else {
					p->next = new ListNode(p1->val);;
					p1 = p1->next;
					p = p->next;
				}
			}
			else if (p1) {
				p->next = new ListNode(p1->val);;
				p1 = p1->next;
				p = p->next;
			}
			else if (p2) {
				p->next = new ListNode(p2->val);
				p2 = p2->next;
				p = p->next;
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

void printList(ListNode *head) {
	while (head) {
		cout << head->val<<' ';
		head = head->next;
	}
}

int main() {
	Solution solu;
	ListNode *l1 = buildList();
	ListNode *l2 = buildList();
	ListNode *res = solu.mergeTwoLists(l1, l2);
	printList(res);
	return 0;
}