/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int min_num = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                min_num = min(min_num, dp[i - j * j]);
            }
            dp[i] = min_num + 1;
        }
        return dp[n];
    }
};
// @lc code=end
