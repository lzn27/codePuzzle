# 131. Palindrome Partitioning（leetcode medium）
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.
```
Input: "aab"
Output:
[
  ["aa","b"],
  ["a","a","b"]
]
```
字符串分割问题，注意回溯法（backtracking）的使用。