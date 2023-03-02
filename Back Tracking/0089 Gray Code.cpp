/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> ret(1 << n);
        for (int i = 0; i < ret.size(); i++)
        {
            ret[i] = (i >> 1) ^ i;
        }
        return ret;
    }
};
// @lc code=end
