//使用递归 利用公式  a^n = a^(n/2) * a^(n/2)  实现 logN 时间复杂度

class Solution {
   public:
    double Power(double base, int exponent) {
        if (base == 0) return 0;
        if (exponent == 0) return 1;
        double ans = Power(base, abs(exponent) >> 1);
        ans = abs(exponent) % 2 == 0 ? ans * ans : ans * ans * base;
        if (exponent > 0)
            return ans;
        else
            return 1.0 / ans;
    }
};
