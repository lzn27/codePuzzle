#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> ans_set;
        vector<int> v;
        int sum = 0;
        recursion(ans_set, v, candidates, target, 0, sum);
        vector<vector<int>> vec;
        for (set<vector<int>>::iterator iter(ans_set.begin()); iter != ans_set.end(); iter++) {
            vec.push_back(*iter);
        }
        return vec;
    }
    void recursion(set<vector<int>>& ans_set, vector<int>& v, const vector<int>& cand, const int& target, int begin, int& sum) {
        if (sum == target) {
            ans_set.insert(v);
            return;
        }
        for (int i = begin; i < cand.size(); i++) {
            if (sum + cand[i] <= target) {
                v.push_back(cand[i]);
                sum += cand[i];
                recursion(ans_set, v, cand, target, i + 1, sum);
                sum -= cand[i];
                v.pop_back();
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
    vector<int> candidates({ 10,1,2,7,6,1,5 });
    vector<vector<int>> vec(solu.combinationSum2(candidates, 8));
    for (vector<vector<int>>::iterator iter(vec.begin()); iter < vec.end(); iter++) {
        for (vector<int>::iterator it((*iter).begin()); it < (*iter).end(); it++)
            cout << *it<<' ';
        cout << endl;
    }

    return 0;
}