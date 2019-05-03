# Valid Parentheses（leetcode_easy）
简单题，括号合法匹配，用stack即可。出现左括号直接push压入栈内，出现右括号就检查栈顶元素，能够匹配就弹出pop，不合法匹配直接结束返回false。最后的stack中一定是空的，否则返回false。

注意边界条件：
- 输入空
- 输入(((((  全部压入最后不为空返回false
- 输入))))  直接第一个就不匹配返回false，但是匹配前要检查stack是否有元素。