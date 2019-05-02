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
		if (head == NULL)
			return head;
		ListNode* fast = head, *slow = head;
		while (n--) {
			if (fast)
				fast = fast->next;
		}
		if (fast == NULL) {//注意边界情况，n=总结点个数的时候，即删除头节点的时候。
			ListNode* p = head;
			head = head->next;
			delete(p);
			return head;
		}
		while (fast->next) {
			fast = fast->next;
			slow = slow->next;
		}
		fast = slow->next;
		slow->next = fast->next;
		delete(fast);
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