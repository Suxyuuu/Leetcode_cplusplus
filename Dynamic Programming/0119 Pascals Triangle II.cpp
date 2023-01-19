/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> ret(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i)
        {
            ret[i] = 1;
            for (int j = i - 1; j >= 1; --j)
            {
                ret[j] += ret[j - 1];
            }
        }
        return ret;
    }
};
// @lc code=end
