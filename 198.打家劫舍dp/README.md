# 198 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。

```c++
class Solution {//f(n)=max(f(n-1),f(n-2)+An)
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)return 0;
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        int x=nums[0],y=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int n=max(y,x+nums[i]);
            x=y;
            y=n;
        }
        return y;
    }
};
```