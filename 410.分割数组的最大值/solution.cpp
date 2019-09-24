#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(m + 1, 0));
        vector<unsigned int> presum(nums.size(), 0);
        presum[0] = nums[0];
        vector<int> leftmax(nums.size(), -1);
        leftmax[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            presum[i] += (presum[i - 1] + nums[i]);
            leftmax[i] = max(nums[i], leftmax[i - 1]);
        }
        for (int i = 1; i < dp.size(); i++) {
            dp[i][1] = presum[i - 1];
            if (i <= m)
                dp[i][i] = leftmax[i - 1];
        }
        for (int j = 2; j <= m; j++) {
            for (int i = j + 1; i <= nums.size(); i++) {
                int nowmin = INT_MAX;
                for (int k = j - 1; k <= i - 1; k++) {
                    nowmin = min(nowmin, max(dp[k][j - 1], (int)(presum[i - 1] - presum[k - 1])));
                }
                dp[i][j] = nowmin;
            }
        }
        return dp[nums.size()][m];
    }
};

int main() {
    Solution solu;
    vector<int> gas{ 1,2,3,4,5 };
    vector<int> cost{ 7,2,5,10,8 };
    auto ans = solu.splitArray(cost, 2);
    return 0;
}