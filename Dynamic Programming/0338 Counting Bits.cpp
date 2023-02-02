/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            // i & (i - 1) 是将i的二进制表示中最右边的1去掉
            ans[i] = ans[i & (i - 1)] + 1;
        }
        return ans;
    }
};
// @lc code=end
