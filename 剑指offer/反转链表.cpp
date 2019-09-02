class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode *pPre=nullptr;
        ListNode *pNode=pHead;
        ListNode *pNext=nullptr;
        while(pNode){
            pNext=pNode->next;
            pNode->next=pPre;
            pPre=pNode;
            pNode=pNext;
        }
        return pPre;
    }
};