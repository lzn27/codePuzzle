#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
                v.push_back(cand[i]);
                sum += cand[i];
                recursion(vec, v, cand, target, i, sum);
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
    vector<int> candidates({ 2,3,5 });
    vector<vector<int>> vec(solu.combinationSum(candidates, 8));
    for (vector<vector<int>>::iterator iter(vec.begin()); iter < vec.end(); iter++) {
        for (vector<int>::iterator it((*iter).begin()); it < (*iter).end(); it++)
            cout << *it<<' ';
        cout << endl;
    }

    return 0;
}