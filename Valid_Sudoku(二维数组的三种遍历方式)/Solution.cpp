#include<iostream>
#include<vector>
using namespace std;

class Solution {//主要问题在于如何简化代码编写
private:
	int hashRow[10];
	int hashCol[10];
	int hash3x3[10];

public:
	bool isValidSudoku(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			fill(hashRow, hashRow + 10, 0);
			for (int j = 0; j < board[i].size(); j++) {//横着遍历
				if (board[i][j] != '.') {
					if (hashRow[board[i][j] - '0'] != 0)
						return false;
					else
						hashRow[board[i][j] - '0']++;
				}
				
				if (i == 0) {//竖着遍历
					fill(hashCol, hashCol + 10, 0);
					for (int k = 0; k < 9; k++) {
						if (board[k][j] != '.') {
							if (hashCol[board[k][j] - '0'] != 0)
								return false;
							else
								hashCol[board[k][j] - '0']++;
						}
					}
				}

				if (i % 3 == 0 && j % 3 == 0) {//3x3遍历
					fill(hash3x3, hash3x3 + 10, 0);
					for (int i2 = i; i2 < i + 3; i2++) {
						for (int j2 = j; j2 < j + 3; j2++) {
							if (board[i2][j2] != '.') {
								if (hash3x3[board[i2][j2] - '0'] != 0)
									return false;
								else
									hash3x3[board[i2][j2] - '0']++;
							}
						}
					}
				}
			}
		}
		return true;
	}
};

int main() {
	Solution solu;
	vector<vector<char>> vec;
	for (int i = 0; i < 9; i++) {
		vector<char> row;
		for (int j = 0; j < 9; j++) {
			char data;
			cin >> data;
			row.push_back(data);
		}
		vec.push_back(row);
	}
	cout<<solu.isValidSudoku(vec);
	return 0;
}