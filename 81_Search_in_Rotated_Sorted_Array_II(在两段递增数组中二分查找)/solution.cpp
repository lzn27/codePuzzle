#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (getans(nums, target) == -1)
            return false;
        else
            return true;
    }
private:
    int getans(const vector<int>& vec, int x) {
        if (vec.size() == 0)
            return -1;
        else
            return getIndex(vec, x, 0, vec.size() - 1);
    }
    int getIndex(const vector<int>& vec, int x, int l, int r) {
        if (l > r)
            return -1;
        int mid = (l + r) / 2;
        if (x == vec[mid])
            return mid;
        if (vec[mid] > vec[l]) {
            if (x < vec[mid] && x >= vec[l])
                return getIndex(vec, x, l, mid - 1);
            else
                return getIndex(vec, x, mid + 1, r);
        }
        else {
            if (vec[mid] < vec[l]) {
                if (x<vec[l] && x>vec[mid])
                    return getIndex(vec, x, mid + 1, r);
                else
                    return getIndex(vec, x, l, mid - 1);
            }
            else {//vec[mid]==vec[l]的情况，如果数组中允许相同的数字，那么必须单独处理该情况，处理方式是直接l+1;
                return getIndex(vec, x, l + 1, r);
            }
        }
    }
};
int main() {
    Solution solu;
    vector<int> vec{ 1,3,1,1,1 };
    cout << solu.search(vec, 3);
    return 0;
}