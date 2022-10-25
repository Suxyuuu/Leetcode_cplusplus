/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        vector<string> ans(numRows);
        int flag = 1;
        int row = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ans[row].push_back(s[i]);
            row += flag;
            if (row == numRows - 1 || row == 0)
            {
                flag = -flag;
            }
        }
        string ansstr;
        for (auto &&row : ans)
        {
            ansstr += row;
        }
        return ansstr;
    }
};
// @lc code=end
