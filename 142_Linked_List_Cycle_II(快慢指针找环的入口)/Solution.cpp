#include<iostream>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//写法一：
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!(head&&head->next))
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        bool flag = false;
        while (fast&&fast->next) {
            if (!flag) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    flag = true;
                    fast = head;
                }
            }
            if (flag) {
                if (fast == slow)
                    return fast;
                slow = slow->next;
                fast = fast->next;
            }
        }
        return NULL;
    }
};

//写法二：
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!(head&&head->next))
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* slow2 = head;
        bool flag = false;
        while (fast&&fast->next) {
            if (flag) {
                if (slow == slow2)
                    return slow;
                slow = slow->next;
                slow2 = slow2->next;
            }
            if (!flag) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                    flag = true;
                }
            }
        }
        slow2 = NULL;
        return NULL;
    }
};