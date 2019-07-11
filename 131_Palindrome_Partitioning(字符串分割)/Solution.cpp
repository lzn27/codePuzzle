#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> v;
        vector<vector<string>> ans;
        recursion(s, 0, v, ans);
        return ans;
    }

    void recursion(string& s, int begin, vector<string>& v, vector<vector<string>>& ans) {
        if (begin == s.size()) {
            ans.push_back(v);
            return;
        }
        for (int i = begin; i < s.size(); i++) {
            string ts(s.begin() + begin, s.begin() + i + 1);
            if (ispali(ts)) {
                v.push_back(ts);
                recursion(s, i + 1, v, ans);
                v.pop_back();
            }
        }

    }

    bool ispali(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};

int main() {
    Solution solu;
    string s = "aab";
    vector<vector<string>> vec(solu.partition(s));

    return 0;
}