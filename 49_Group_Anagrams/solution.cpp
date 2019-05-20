#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

class Solution {
private:
	map<multiset<char>,int> s;
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> vec;
		int size = 0;
		for (int i = 0; i < strs.size(); i++) {
			multiset<char> ts;
			for (int j = 0; j < strs[i].size(); j++) {
				ts.insert(strs[i][j]);
			}
			auto it = s.find(ts);
			if (it == s.end()) {
				s.insert(make_pair(ts, size++));
				vector<string> tv = { strs[i] };
				vec.push_back(tv);
			}
			else {
				vec[it->second].push_back(strs[i]);
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