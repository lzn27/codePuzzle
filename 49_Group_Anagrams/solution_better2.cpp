//更优雅，但是会占用更多空间，时间一样
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
private:
	unordered_map<string,vector<string>> m;
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> vec;
		for (string s : strs) {
			string temp = s;
			sort(temp.begin(), temp.end());
			m[temp].push_back(s);
		}
		for (auto it : m) {
			vec.push_back(it.second);
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
