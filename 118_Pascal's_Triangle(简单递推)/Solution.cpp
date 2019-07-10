#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        if (numRows == 0)
            return vec;
        vector<int> *pv = new vector<int>();
        pv->push_back(1);
        vec.push_back(*pv);
        delete pv;
        for (int i = 2; i <= numRows; i++) {
            vec.push_back(gen(vec[i - 2]));
        }
        return vec;
    }

    vector<int> gen(const vector<int>& vec) {
        vector<int> v(vec.size() + 1);
        if (vec.size() == 1) {
            v[0] = 1;
            v[1] = 1;
            return v;
        }
        v[0] = 1;
        for (int i = 1; i < vec.size(); i++) {
            v[i]=vec[i] + vec[i - 1];
        }
        v[vec.size()] = 1;
        return v;
    }
};

int main() {
    Solution solu;
    vector<vector<int>> ans=solu.generate(6);
    for (vector<vector<int>>::iterator iter = ans.begin(); iter < ans.end(); iter++) {
        for (vector<int>::iterator it = (*iter).begin(); it < (*iter).end(); it++)
            cout << *it;
        cout << endl;
    }
    return 0;
}