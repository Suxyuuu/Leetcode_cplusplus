/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution
{
public:
    int ans;

    int findTargetSumWays(vector<int> &nums, int target)
    {
        dfs(nums, 0, 0, target);
        return ans;
    }

    void dfs(vector<int> &nums, int curpos, long sum, int target)
    {
        if (curpos == nums.size() && sum == target)
        {
            ans++;
            return;
        }
        else if (curpos == nums.size())
        {
            return;
        }
        else
        {
            dfs(nums, curpos + 1, sum + nums[curpos], target);
            dfs(nums, curpos + 1, sum - nums[curpos], target);
        }
    }
};
// @lc code=end
