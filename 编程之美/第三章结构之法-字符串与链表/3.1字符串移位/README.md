提供了两种解法：
- 时间O(N*M)，手动寻找匹配
- 时间O(N+M)，**对一个字符串s做循环移位所得到的所有字符串都是字符串s+s的子字符串。**。因此，直接利用std::string.find函数即可。
```C++
if ((s1 + s1).find(s2) != std::string::npos)
    return true;
else
    return false;
```