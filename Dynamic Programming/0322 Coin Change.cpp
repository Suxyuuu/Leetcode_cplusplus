/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
        {
            return 0;
        }
        if (amount < 0)
        {
            return -1;
        }
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (auto &&coin : coins)
            {
                if (i < coin)
                {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
    }
};
// @lc code=end
