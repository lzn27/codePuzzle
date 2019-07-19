# 142. Linked List Cycle II（leetcode medium）
快慢指针找链表环的入口，具体为：当快慢指针相遇时，定义第三个慢指针slow2=head，slow继续慢走，slow2从头慢走，当slow和slow2**第一次**相遇时的位置即为环的入口点。