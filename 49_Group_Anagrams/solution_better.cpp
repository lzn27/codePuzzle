#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
private:
	unordered_map<string,int> m;
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> vec;
		int size = 0;
		for (int i = 0; i < strs.size(); i++) {
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			if (m.find(temp) == m.end()) {
				m.insert(make_pair(temp, size++));
				vector<string> tv = { strs[i] };
				vec.push_back(tv);
			}
			else {
				vec[m[temp]].push_back(strs[i]);
			}
		}
		return vec;
	}
};

int main() {
	Solution solu;
	vector<string> strs = { "boo","bob","fd","df","df" };
	vector<vector<string>> ans=solu.groupAnagrams(strs);
	return 0;
}