/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }

        int i_2 = nums[0];
        int i_1 = max(nums[0], nums[1]);
        int ans = i_1;
        for (int i = 2; i < n; i++)
        {
            ans = max(i_2 + nums[i], i_1);
            i_2 = i_1;
            i_1 = ans;
        }
        return ans;
    }
};
// @lc code=end
