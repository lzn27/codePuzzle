# Generate Parentheses（leetcode_medium）
递归即可。

一点思考：
1. 写法上简化空间复杂度
```C++
//不好的写法
s+='(';
recursion(vec, s, ln - 1, rn + 1);
s.erase(s.size()-1);

//更好的写法
recursion(vec, s + '(', ln - 1, rn + 1); 
```