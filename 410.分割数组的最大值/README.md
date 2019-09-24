# 410 leetcode hard

dp[i][j] =  min( max(dp[k][j-1],sum(k+1,i)) ),k从j-1到i-1.