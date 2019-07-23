#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;


//Definition for singly - linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* phead = new ListNode(0);
        phead->next = head;//添加一个头节点
        ListNode* p = head;
        ListNode* p_pre = phead;
        while (p) {
            ListNode* j_pre = phead;
            ListNode* j = phead->next;

            while (j->val < p->val) {
                j_pre = j;
                j = j->next;
            }
            if (j != p) {
                p_pre->next = p->next;
                j_pre->next = p;
                p->next = j;
                p = p_pre->next;
            }
            else {
                p_pre = p;
                p = p->next;
            }
        }
        return phead->next;
    }
};
int main() {
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    Solution solu;
    head=solu.sortList(head);

    return 0;
}