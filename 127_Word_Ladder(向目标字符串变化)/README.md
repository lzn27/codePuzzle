# 127. Word Ladder（leetcode medium）
题目：
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

给定两个word，beginWord和endWord，还有一个wordList，要求按照wordList中的word从beginWord变化到endWord，且每次只能改变一个字母。
```
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
```
该题最值得的经验是：寻找与word1相邻的word2时，可以采用暴力循环查找的方法，比如寻找与hit相邻的word可以遍历hit的三个位置，每个位置都用26个字母一一替换测试，总共也就3*26次，是个常数级方法，很快，每次查找可以在set中查找，红黑树logn的速度也不错的。