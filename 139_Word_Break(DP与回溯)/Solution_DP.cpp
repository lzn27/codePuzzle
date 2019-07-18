#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> unset(wordDict.begin(), wordDict.end());
        unordered_set<string> visit;
        return dypro(unset, s);
    }

    bool dypro(unordered_set<string>& unset, string s) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    if (unset.find(s.substr(j, i - j)) != unset.end()) {
                        dp[i] = true;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
//----------------------
int main() {
    Solution solu;
    vector<string> vec = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    cout << solu.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", vec);
    return 0;
}