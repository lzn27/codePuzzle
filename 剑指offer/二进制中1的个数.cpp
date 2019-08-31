//常规方法：
    int  NumberOf1(int n) {
        unsigned int x = 1;
        int ans = 0;
        while (x != 0) {
            unsigned int t = x & n;
            if ((x&n) != 0)ans++;//注意！！&运算符的优先级比 != 低，所以必须加上括号！！
            x = x << 1;
        }
        return ans;
    }


//特别解法：
int numberOf1(int n){
    int count=0;
    while(n){
        count++;
        n=n&(n-1);
    }
    return count;
}