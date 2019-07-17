# 114. Flatten Binary Tree to Linked List(leetcode medium)
注意引用指针的用法，
- 函数传参时，即使是传指针也是传值，递归返回时，指针的值会变回去。此时可以使用多级指针或者指针的引用。