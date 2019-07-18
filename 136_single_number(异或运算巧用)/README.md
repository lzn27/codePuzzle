# single number (leetcode easy)
- 容易想的方法是hash table
- 更精巧的方法是利用异或运算：

```
- If we take XOR of zero and some bit, it will return that bit
                      a⊕0=a
- If we take XOR of two same bits, it will return 0
                      a⊕a=0
- a⊕b⊕a = (a⊕a)⊕b = 0⊕b = b
```
所以把所有的数字全部异或起来就能得到那个唯一的没有成对出现的数字。