# Letter Combinations of a Phone Number（leetcode_medium）
**for循环内加递归，进行未知for循环层数的遍历。**

```C++
for (int i = 0; i < str.size(); i++) {
    s += str[i];//遍历加上，递归返回后要再去掉
    if (id == digits.size() - 1)//边界判断，是否进入了最深层递归
        res.push_back(s);//进入最深层的操作
    else
        recursion(digits, id + 1, s, res);//携带本次for循环的结果再次进入递归
    s = s.substr(0, s.size() - 1);//再去掉
}
```
