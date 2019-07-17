#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> a(n + 1, 0);
        a[0] = 1;
        a[1] = 1;
        for (int i = 2; i < a.size(); i++) {
            for (int j = 0; j < i / 2; j++) {
                a[i] += a[j] * a[i - 1 - j];
            }
            a[i] *= 2;
            if (i % 2 == 1) {
                a[i] += a[i / 2] * a[i / 2];
            }
        }
        return a[n];
    }
};
//----------------------
int main() {
    Solution solu;
    cout << solu.numTrees(4);

    return 0;
}