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

        for (int subLength = 1; subLength < length; subLength <<= 1) {
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;
                curr->next = nullptr;
                curr = head2;
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {
                    next = curr->next;
                    curr->next = nullptr;
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;
                while (prev->next != nullptr) {
                    prev = prev->next;
                }
                curr = next;
            }
        }
        return dummyHead->next;
    }

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/sort-list/solution/pai-xu-lian-biao-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。