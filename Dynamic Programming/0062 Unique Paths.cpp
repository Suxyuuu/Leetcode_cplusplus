/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // 可以用动态规划 但不如直接用数学
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y)
        {
            ans = ans * x / y;
        }
        return ans;
    }
};
// @lc code=end
