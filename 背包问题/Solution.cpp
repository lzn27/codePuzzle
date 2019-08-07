#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dimension2() {//用二位数组好理解
    int W, num;
    cin >> W >> num;
    vector<vector<int>> dp(num + 1, vector<int>(W + 1, 0));
    int weight, v;
    cin >> weight >> v;
    for (int i = 1; i <= W; i++) {
        if (i >= weight)dp[1][i] = v;
    }
    for (int i = 2; i <= num; i++) {
        int weight, v;
        cin >> weight >> v;
        for (int j = 1; j <= W; j++) {
            if (j > weight)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + v);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[num][W];
}

void dimension1() {//节省内存，用一维数组
    int W, num;
    cin >> W >> num;
    vector<int> dp(W + 1, 0);
    int weight, v;
    cin >> weight >> v;
    for (int i = 1; i <= W; i++) {
        if (i >= weight)dp[i] = v;
    }
    for (int i = 2; i <= num; i++) {
        int weight, v;
        cin >> weight >> v;
        for (int j = W; j >= 1; j--) {
            if (j > weight)
                dp[j] = max(dp[j], dp[j - weight] + v);
            else
                dp[j] = dp[j];
        }
    }
    cout << dp[W];
}


int main() {
    
    return 0;
}