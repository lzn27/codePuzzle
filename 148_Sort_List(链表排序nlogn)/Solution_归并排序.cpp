#include<iostream>

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
        if (head==NULL||head->next==NULL)
            return head;
        ListNode* fast(head);
        ListNode* slow(head);
        while (fast&&fast->next&&fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = NULL;
        slow = sortList(head);
        fast = sortList(fast);
        return merge(slow, fast);
    }
private:
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        ListNode* head;
        if (p1->val < p2->val) {
            head = p1;
            p1 = p1->next;
        }
        else {
            head = p2;
            p2 = p2->next;
        }
        ListNode*p = head;
        while (p1&&p2) {
            if (p1->val > p2->val) {
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
            else {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }
        }
        if (p1)
            p->next = p1;
        if (p2)
            p->next = p2;
        return head;
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