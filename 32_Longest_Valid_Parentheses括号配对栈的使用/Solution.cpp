#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0)
            return 0;
        //stack<char> sta;
        vector<int> vec;
        for (int i = 0; i < s.size(); i++) {
            if (vec.size() == 0 || s[i] == '(') {
                //sta.push(s[i]);
                vec.push_back(i);
            }
            else {
                if (s[vec.back()] == '(') {
                    //sta.pop();
                    vec.pop_back();
                }
                else {
                    //sta.push(s[i]);
                    vec.push_back(i);
                }
            }
        }
        if (vec.size() == 0)
            return s.size();
        else {
            int MAX = max(vec[0] - 0, (int)s.size() - 1 - vec[vec.size() - 1]);
            for (int i = 1; i < vec.size(); i++) {
                if (vec[i] - vec[i - 1] - 1 > MAX)
                    MAX = vec[i] - vec[i - 1] - 1;
            }
            return MAX;
        }
    }
};

int main() {
    Solution solu;
    cout << solu.longestValidParentheses("(()()()()()())((((()))))))))");
    return 0;
}