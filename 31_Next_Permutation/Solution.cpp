#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int si = -1, sj = -1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    if (i > si) {
                        si = i;
                        sj = j;
                    }
                    if (i == si && nums[j] < nums[sj]) {
                        sj = j;
                    }
                }
            }
        }
        if (si != -1) {
            swap(nums[si], nums[sj]);
            sort(nums.begin() + si + 1, nums.end());
            return;
        }
        else {
            reverse(nums.begin(), nums.end());
        }
    }
};

int main() {
    Solution solu;
    vector<int> vec = { 4,2,0,2,3,2,0 };
    solu.nextPermutation(vec);
    vector<int>::iterator iter(vec.begin());
    while (iter != vec.end()) {
        cout << *iter << ' ';
        iter++;
    }
    return 0;
}