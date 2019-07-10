# 121. Best Time to Buy and Sell Stock(leetcode easy)
类似于Dijkstra算法更新思想，每次新加入一个新值，就判断是否更新。代码值得不时看一看。

题目：
你有一个数组，第i个元素是一个给定的股票在第i天的价格。如果你只被允许最多买一次卖一次，设计一个算法来找到最大的利润。注意，在出售股票前，必须先购买。

```C++
int maxProfit(vector<int>& prices) {
    int min = INT_MAX;
    int ans = 0;
    for (int i = 0; i < prices.size(); i++) {
        min = std::min(min, prices[i]);
        if (prices[i] - min > ans)
            ans = prices[i] - min;
    }
    return ans;
}
```