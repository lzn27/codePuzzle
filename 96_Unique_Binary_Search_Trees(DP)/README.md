# 96. Unique Binary Search Trees(leetcode medium)
```
Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```
- 多递推几步，方法很快就出来
- 递归改成循环，效率更高，可以开一个数组存放循环产生的中间结果。