# 48. Rotate Image (leetcode Medium)
两个要点：
- 旋转四个值的左边关系是：按顺时针(i,j)、(j,size-1-i)、(size-1-i,size-1-j)、(size-1-j,i)
- 由外圈向里圈遍历的循环方式是：
```C++
for (int i = 0; i < size / 2; i++){
    for (int j = i; j < size - i - 1; j++){
        //swap 四个值
    }
}
```

#### 附录：
一种书写更优雅，值得玩味的书写方法是：值得研究一下
```C++
int n = matrix.size();
        int a = 0;
        int b = n-1;
        while(a<b){
            for(int i=0;i<(b-a);++i){
                swap(matrix[a][a+i], matrix[a+i][b]);
                swap(matrix[a][a+i], matrix[b][b-i]);
                swap(matrix[a][a+i], matrix[b-i][a]);
            }
            ++a;
            --b;
        }
```