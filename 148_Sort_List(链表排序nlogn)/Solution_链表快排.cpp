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
//链表形式的快速排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL)
            return head;
        ListNode* tail = head;
        while (tail->next)tail = tail->next;
        qs(head, tail);
        return head;
    }
private:
    void qs(ListNode* head, ListNode* tail) {
        if (head == NULL || head == tail)
            return;
        if (head == tail->next)
            return;
        ListNode* s_pre = part(head, tail);

        if (s_pre == head)
            qs(head->next, tail);
        else {
            qs(head, s_pre);
            qs(s_pre->next->next, tail);
        }
    }
    ListNode* part(ListNode* head,ListNode* tail) {
        int n = tail->val;
        ListNode* store = head;
        ListNode* s_pre = store;
        ListNode* p = head;
        while (p != tail->next) {
            if (p->val < n) {
                swap(p->val, store->val);
                s_pre = store;
                store = store->next;
            }
            p = p->next;
        }
        swap(tail->val, store->val);
        return s_pre;
    }
};
int main() {

    return 0;
}