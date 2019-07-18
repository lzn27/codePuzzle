#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};
//----------------------
int main() {
    Solution solu;
    vector<int> vec = { 1,2,2,4,4 };
    cout << solu.singleNumber(vec);
    return 0;
}