#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if (n == 0 || n == 1)
            return 1;
        int i = 0, j = n - 1;
        int ans = 0;
        while (i < j) {
            ans += numTrees(i) * numTrees(j);
            i++;
            j--;
        }
        ans *= 2;
        if (n % 2 == 1) {
            ans += numTrees(n / 2)*numTrees(n / 2);
        }
        return ans;
    }
};
//----------------------
int main() {
    Solution solu;
    cout << solu.numTrees(3);

    return 0;
}