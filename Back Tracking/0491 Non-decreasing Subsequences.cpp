/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] Non-decreasing Subsequences
 */

// @lc code=start
class Solution
{
public:
    vector<int> path;
    vector<vector<int>> ans;

    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        dfs(0, INT_MIN, nums);
        return ans;
    }

    void dfs(int curpos, int last_num, vector<int> &nums)
    {
        if (curpos == nums.size())
        {
            if (path.size() >= 2)
            {
                ans.emplace_back(path);
            }
            return;
        }
        if (nums[curpos] >= last_num)
        {
            path.emplace_back(nums[curpos]);
            dfs(curpos + 1, nums[curpos], nums);
            path.pop_back();
        }
        if (nums[curpos] != last_num)
        {
            dfs(curpos + 1, last_num, nums);
        }
    }
};
// @lc code=end
