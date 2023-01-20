/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int row = triangle.size();
        vector<vector<int>> ans(row, vector<int>(row));
        // 自下而上遍历 最后一行作初始值
        for (int i = 0; i < row; i++)
        {
            ans[row - 1][i] = triangle[row - 1][i];
        }

        for (int i = row - 2; i >= 0; --i)
        {
            for (int j = 0; j <= i; ++j)
            {
                ans[i][j] = min(ans[i + 1][j], ans[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return ans[0][0];
    }
};
// @lc code=end
