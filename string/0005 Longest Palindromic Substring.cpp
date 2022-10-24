/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        if (len < 2)
            return s;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int ans = 1;
        int begin = 0;
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = true;
        }
        for (int j = 1; j < len; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (s[i] != s[j])
                {
                    continue;
                }
                else if (j - i < 3)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j])
                {
                    if (j - i + 1 > ans)
                    {
                        ans = j - i + 1;
                        begin = i;
                    }
                }
            }
        }
        return s.substr(begin, ans);
    }
};
// @lc code=end
