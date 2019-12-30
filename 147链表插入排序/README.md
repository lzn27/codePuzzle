# 147 链表插入排序
```c++
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode phead(-1);//大胆添加头节点
        ListNode* hhead=&phead;
        hhead->next=head;
        ListNode* p=head;
        ListNode* pre=hhead;//大胆使用pre节点
        while(p){
            ListNode* ttp=hhead;//大胆使用pre节点
            ListNode* tp=hhead->next;
            while(tp!=p&&tp->val<=p->val){
                ttp=tp;
                tp=tp->next;
            }
            if(tp==p){
                pre=p;
                p=p->next;
            }
            else{
                pre->next=p->next;
                p->next=ttp->next;
                ttp->next=p;
                p=pre->next;
            }
        }
        return hhead->next;
    }
};
```
