#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
class Solution {
public:
    bool isChild(string s1, string s2) {
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] == s2[0]) {
                int j = i;
                for (int p = 0; p < s2.size(); p++) {
                    if (s1[j] != s2[p])
                        break;
                    else {
                        if (p == s2.size() - 1)
                            return true;
                        if (j < s1.size() - 1)
                            j++;
                        else
                            j = 0;
                    }
                }

            }
        }
        return false;
    }

    bool better(string s1, string s2) {
        s1 = s1 + s1;
        if (s1.find(s2)!=std::string::npos)
            return true;
        else
            return false;
    }
};



int main() {
    Solution solu;
    cout << solu.better("AABCD", "CDAAE");
    return 0;
}