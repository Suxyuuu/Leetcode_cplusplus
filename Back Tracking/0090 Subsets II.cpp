/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution
{
public:
    vector<int> temp;
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }

    void dfs(const vector<int> &nums, int cur)
    {
        ans.emplace_back(temp);
        for (int i = cur; i < nums.size(); i++)
        {
            if (i > cur && nums[i - 1] == nums[i])
            {
                continue;
            }
            temp.emplace_back(nums[i]);
            dfs(nums, i + 1);
            temp.pop_back();
        }
    }
};
// @lc code=end
