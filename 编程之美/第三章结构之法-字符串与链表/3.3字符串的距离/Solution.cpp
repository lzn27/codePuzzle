#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
class Solution {
public:
    int getdistance(const string& s1, const string& s2) {
        return getdis(s1, 0, s1.size() - 1, s2, 0, s2.size() - 1);
    }
private:
    int getdis(const string& s1, int be1, int end1, const string& s2, int be2, int end2) {
        if (be1 > end1) {
            return end2 - be2 + 1;
        }
        if (be2 > end2)
            return end1 - be1 + 1;
        if (s1[be1] == s2[be2])
            return getdis(s1, be1 + 1, end1, s2, be2 + 1, end2);
        else {
            int len0 = 1 + getdis(s1, be1, end1, s2, be2 + 1, end2);
            int len1 = 1 + getdis(s1, be1 + 1, end1, s2, be2, end2);
            int len2 = 1 + getdis(s1, be1 + 1, end1, s2, be2 + 1, end2);

            return getmin(len0, len1, len2);
        }
    }
    int getmin(int a1, int a2, int a3) {
        int b1 = min(a1, a2);
        return min(b1, a3);
    }
};



int main() {
    Solution solu;
    cout << solu.getdistance("lizining", "lizining");
    return 0;
}