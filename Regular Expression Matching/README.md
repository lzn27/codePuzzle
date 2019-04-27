# Regular Expression Matching (hard)
## 递归方法：
对*的情况分成两种讨论：string s:text，string p:pattern
- *的作用为0次幂的情况
    - 递归判断*后的字符串与本身s的匹配。
- *的作用为1或大于1次幂的情况
    - 递归判断s去掉最前面字符后与完整p的匹配。

- 如果没有找到*号，那么s，p均向后移动一位，然后递归判断，知道遇见\*号。


递归要注意边界条件