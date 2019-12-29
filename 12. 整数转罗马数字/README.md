# 12. 整数转罗马数字

例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

- I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
- X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
- C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。

```c++
class Solution {
public:
    string intToRoman(int num) {
        string str("");
        while(num){
            str+=getone(num);
        }
        return str;
    }

    string getone(int& x){
        if(x>=1000){
            x-=1000;
            return string("M");
        }
        if(x>=900){
            x-=900;
            return string("CM");
        }
        if(x>=500){
            x-=500;
            return string("D");
        }
        if(x>=400){
            x-=400;
            return string("CD");
        }
        if(x>=100){
            x-=100;
            return string("C");
        }
        if(x>=90){
            x-=90;
            return string("XC");
        }
        if(x>=50){
            x-=50;
            return string("L");
        }
        if(x>=40){
            x-=40;
            return string("XL");
        }
        if(x>=10){
            x-=10;
            return string("X");
        }
        if(x>=9){
            x-=9;
            return string("IX");
        }
        if(x>=5){
            x-=5;
            return string("V");
        }
        if(x>=4){
            x-=4;
            return string("IV");
        }
        if(x>=1){
            x-=1;
            return string("I");
        }
        return string("");
    }

};
```