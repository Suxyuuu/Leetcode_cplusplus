/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution
{
public:
    // 也可以用单调栈做 此处为练习DP
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0 || n == 1)
        {
            return 0;
        }
        // vector<int> dp(n); // 存放每个位置前面的最小值
        // dp[0] = INT_MAX;
        // 由于每次只与前一个最小值有关，所以进行优化
        int pre_min = INT_MAX;
        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            pre_min = min(pre_min, prices[i - 1]);
            ans = max(ans, prices[i] - pre_min);
        }
        return ans;
    }
};
// @lc code=end
