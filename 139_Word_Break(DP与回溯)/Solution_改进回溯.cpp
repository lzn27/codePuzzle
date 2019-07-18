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
        return backtrack(unset, s, visit);
    }

    bool backtrack(unordered_set<string>& unset, string s, unordered_set<string>& visit) {
        if (visit.find(s) == visit.end()) {
            for (int i = 1; i <= s.size(); i++) {
                string ts = s.substr(0, i);
                if (unset.find(ts) != unset.end()) {
                    if (i == s.size() || backtrack(unset, s.substr(i), visit))
                        return true;
                }
            }
            visit.insert(s);
        }
        return false;
    }
};
//----------------------
int testmain2() {
    Solution solu;
    vector<string> vec = { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" };
    cout << solu.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", vec);
    return 0;
}