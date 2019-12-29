# 43. 字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

输入: num1 = "123", num2 = "456"

输出: "56088"
1. num1 和 num2 的长度小于110。
2. num1 和 num2 只包含数字 0-9。
3. num1 和 num2 均不以零开头，除非是数字 0 本身。
4. 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
```c++
//方法一竖式乘法
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        string res(n1+n2,'0');
        for(int i=n2-1;i>=0;i--){
            for(int j=n1-1;j>=0;j--){
                int temp=(res[i+j+1]-'0')+(num1[j]-'0')*(num2[i]-'0');
                res[i+j+1]=temp%10+'0';//当前位
                res[i+j]+=temp/10; //前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
            }
        }     
        //去除首位'0'
        int begin=0;
        while(res[begin]=='0'&&begin<res.size()-1)begin++;
        return res.substr(begin);
    }
};
//方法二暴力相乘
class Solution {
public:
    string multiply(string num1, string num2) {
        string str;
        for(int i=num1.size()-1;i>=0;i--){
            string str2(num2.size()+1,'0');//注意string提前设好大小，显著提高效率
            int head2=str2.size()-1;
            int step=0;
            for(int j=num2.size()-1;j>=0;j--){
                int x=(num1[i]-'0')*(num2[j]-'0')+step;
                step=x/10;
                str2[head2--]=x%10+'0';
            }
            if(step!=0)
                str2[head2--]=step+'0';
            
            str2+=string(num1.size()-1-i,'0');
            str=addstr(str,str2);
        }
        int begin=0;
        while(str[begin]=='0'&&begin<str.size()-1)begin++;
        return str.substr(begin);
    }

    string addstr(const string& num1,const string& num2){
        string str(max(num1.size(),num2.size())+1,'0');
        int i=num1.size()-1,j=num2.size()-1;
        bool step=0;
        int head=str.size()-1;
        while(i>=0||j>=0){
            int n1=i>=0?num1[i--]-'0':0;
            int n2=j>=0?num2[j--]-'0':0;
            int x=n1+n2;
            x=step?x+1:x;
            if(x>=10){
                step=1;
                x-=10;
            }
            else{
                step=0;
            }
            str[head--]=x+'0';
        }
        if(step)
            str[head--]='1';
        return str;
    }
};
```