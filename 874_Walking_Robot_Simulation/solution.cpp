#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;



struct ord {
    int x;
    int y;
    int direction;
    ord(int X, int Y) :x(X), y(Y), direction(1) {}
};
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = { 1,0,-1,0 };
        int dy[4] = { 0, 1, 0, -1 };
        set<pair<int, int>> obs_pair;
        for (int i = 0; i < obstacles.size(); i++) {
            obs_pair.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        }
        ord ans(0, 0);
        int res = 0;
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -1) {
                if (ans.direction == 0)
                    ans.direction = 3;
                else
                    ans.direction--;
            }
            else if (commands[i] == -2) {
                if (ans.direction == 3)
                    ans.direction = 0;
                else
                    ans.direction++;
            }
            else {
                for (int j = 0; j < commands[i]; j++) {
                    int xn = ans.x + dx[ans.direction];
                    int yn = ans.y + dy[ans.direction];
                    if (obs_pair.find(make_pair(xn, yn)) == obs_pair.end()) {
                        ans.x = xn;
                        ans.y = yn;
                        res = max(res, ans.x*ans.x + ans.y*ans.y);
                    }
                    else {
                        break;
                    }
                }
            }
        }
        return res;
    }

};

int main() {
    Solution solu;
    vector<int> commands{ 2,-2,2,-2,2,-2,2 };
    vector<vector<int>> obstacles{ vector<int>{2,4} };
    cout << solu.robotSim(commands, obstacles);
    return 0;
}