//Remove Nth Node From End of List
//leetcode medium
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* start = new ListNode(0);//增加一个节点
		start->next = head;
		ListNode *fast = start, *slow = start;
		while (n--) {
			if(fast->next)
				fast = fast->next;
		}
		while (fast->next) {
			slow = slow->next;
			fast = fast->next;
		}
		fast = slow->next;
		slow->next = fast->next;
		delete(fast);
		head = start->next;
		delete(start);
		return head;
	}
};

ListNode* buildList() {
	char c;
	int num;
	cin >> num;
	c = getchar();
	ListNode* head = new ListNode(num);
	ListNode* p = head;
	while (c!='\n') {
		cin >> num;
		c = getchar();
		ListNode* temp = new ListNode(num);
		p->next = temp;
		p = p->next;
	}
	return head;
}

int main() {
	Solution solu;
	ListNode* head = buildList();
	int n;
	cin >> n;
	head = solu.removeNthFromEnd(head, n);
	ListNode* p = head;
	while (p) {
		cout << p->val << ' ';
		p = p->next;
	}
	return 0;
}