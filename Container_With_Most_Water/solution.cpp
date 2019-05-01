#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxArea(vector<int>& height) {
		int max = 0;
		int i = 0, j = height.size() - 1;
		while (j > i) {
			int v = (j - i)*min(height[i], height[j]);
			if (v > max)
				max = v;
			if (height[i] < height[j])
				i++;
			else
				j--;
		}
		return max;
	}
};

int main() {
	Solution solu;
	vector<int> vec = {	1,8,6,2,5,4,8,3,7};
	cout << solu.maxArea(vec);
	return 0;
}