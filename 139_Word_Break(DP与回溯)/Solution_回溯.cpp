#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> unset(wordDict.begin(), wordDict.end());
        return backtrack(unset, s);
    }

    bool backtrack(unordered_set<string>& unset, string s) {
        for (int i = 1; i <= s.size(); i++) {
            string ts = s.substr(0, i);
            if (unset.find(ts) != unset.end()) {
                if (i == s.size() || backtrack(unset, s.substr(i)))
                    return true;
            }
        }
        return false;
    }
};
//----------------------
int testmain() {
    Solution solu;
    vector<string> vec = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    cout << solu.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", vec);
    return 0;
}