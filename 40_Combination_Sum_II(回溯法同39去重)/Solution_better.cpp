#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> vec;
        vector<int> v;
        int sum = 0;
        recursion(vec, v, candidates, target, 0, sum);
        return vec;
    }
    void recursion(vector<vector<int>>& vec, vector<int>& v, const vector<int>& cand, const int& target, int begin, int& sum) {
        if (sum == target) {
            vec.push_back(v);
            return;
        }
        for (int i = begin; i < cand.size(); i++) {
            if (sum + cand[i] <= target) {
                if ((i == begin || cand[i] != cand[i - 1])) {//简化判断重复，意思是在已经排序后的情况下，已经测试过的点跳过不再测试，省略了set去重的使用
                    v.push_back(cand[i]);//注意判断条件的书写，||用来剔除例外情况，用笔在纸上手动试一下，往往可以得到比较好的解法。
                    sum += cand[i];
                    recursion(vec, v, cand, target, i + 1, sum);
                    sum -= cand[i];
                    v.pop_back();
                }
            }
            else {
                return;
            }
        }
    }
};
//----------------------
int main() {
    Solution solu;
    vector<int> candidates({ 5,1,2,2,2 });
    vector<vector<int>> vec(solu.combinationSum2(candidates, 5));
    for (vector<vector<int>>::iterator iter(vec.begin()); iter < vec.end(); iter++) {
        for (vector<int>::iterator it((*iter).begin()); it < (*iter).end(); it++)
            cout << *it<<' ';
        cout << endl;
    }

    return 0;
}