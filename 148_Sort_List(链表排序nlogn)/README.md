# 148. sort list (leetcode medium)
- 插入排序留意指针运算，指针多了容易乱指。
- 快排key的选择要留意
- 链表排序的最佳方法是归并排序，时间O(nlogn)，空间O(1)。
- 在递归中新建头节点会占用较多空间
- 快慢指针在边缘状态的处理要留意，合理使用以下两种写法：
```C++
//第一种
while (fast&&fast->next&&fast->next->next) {
    fast = fast->next->next;
    slow = slow->next;
}

//第二种,注意这里的判断，少一个会让指针更向后移动一次，这在处理很短的链表，比如只有两个节点的时候尤为需要留意
while (fast&&fast->next) {
    fast = fast->next->next;
    slow = slow->next;
}
```