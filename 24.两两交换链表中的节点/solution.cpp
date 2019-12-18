struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* phead = new ListNode(0);
        ListNode* ans_pre = phead;
        phead->next = head;
        ListNode* pre = nullptr;
        while (pre != phead) {
            pre = phead;
            phead = aftswap(phead);
        }
        ListNode* ans = ans_pre->next;
        delete ans_pre;
        return ans;
    }
    ListNode* aftswap(ListNode* head) {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)return head;
        ListNode* p1 = head->next;
        ListNode* p2 = head->next->next;
        head->next = p2;
        p1->next = p2->next;
        p2->next = p1;
        return p1;
    }
};