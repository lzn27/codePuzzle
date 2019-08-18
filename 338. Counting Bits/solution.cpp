#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        unsigned int x = num;
        vector<int> vec(x+1,0);
        for (unsigned int i = 0; i <= x; i++) {
            vec[i] = getOneNum(i);
        }
        return vec;
    }
private:
    int getOneNum(unsigned int x) {
        int res = 0;
        while (x) {
            if (x & 1==1) {
                res++;
            }
            x=x >> 1;
        }
        return res;
    }
};

int main() {
    Solution slou;
    vector<int> vec=slou.countBits(2);
    return 0;
}