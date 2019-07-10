#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            min = std::min(min, prices[i]);
            if (prices[i] - min > ans)
                ans = prices[i] - min;
        }
        return ans;
    }
};

int main() {
    Solution solu;
    vector<int> vec = { 7,6,4,3,1 };
    cout << solu.maxProfit(vec);
    return 0;
}