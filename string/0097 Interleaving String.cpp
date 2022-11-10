/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size())
        {
            return false;
        }
        vector<vector<bool>> dp(2, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i > 0)
                {
                    dp[i % 2][j] = dp[(i - 1) % 2][j] && (s1[i - 1] == s3[i + j - 1]);
                }
                if (j > 0)
                {
                    dp[i % 2][j] = dp[i % 2][j] || (dp[i % 2][j - 1] && (s2[j - 1] == s3[i + j - 1]));
                }
            }
        }
        return dp[m % 2][n];
    }
};
// @lc code=end
