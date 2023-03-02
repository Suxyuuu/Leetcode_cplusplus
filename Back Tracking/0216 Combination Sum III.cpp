/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

// @lc code=start
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum3(int k, int n)
    {
        dfs(0, k, n);
        return ans;
    }

    void dfs(int pre_choice, int len, int target)
    {
        if (len == 1)
        {
            for (int i = pre_choice + 1; i <= 9; i++)
            {
                if (i == target)
                {
                    path.emplace_back(i);
                    ans.emplace_back(path);
                    path.pop_back();
                    return;
                }
            }
            return;
        }
        else
        {
            for (int i = pre_choice + 1; i <= 9; i++)
            {
                path.emplace_back(i);
                dfs(i, len - 1, target - i);
                path.pop_back();
            }
        }
    }
};
// @lc code=end
