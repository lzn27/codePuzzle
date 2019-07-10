#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    bool isPalindrome(string s) {
        int i(0);
        int j(s.size() - 1);
        while (j > i) {
            while (i < j && !isalpha(s[i]) && !isalnum(s[i]))
                i++;
            while (i < j && !isalpha(s[j]) && !isalnum(s[j]))
                j--;
            if (i < j) {
                if (tolower(s[i]) != tolower(s[j]))
                    return false;
                i++;
                j--;
            }
        }
        return true;
    }
};

int main() {
    Solution solu;
//略
    return 0;
}