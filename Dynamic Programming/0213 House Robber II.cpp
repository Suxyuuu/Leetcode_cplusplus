/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] House Robber II
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
        else if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        else
        {
            return max(rob2(nums, 0, n - 2), rob2(nums, 1, n - 1));
        }
    }

    int rob2(vector<int> &nums, int begin, int end)
    {
        int n = end - begin + 1;
        int i_2 = nums[begin];
        int i_1 = max(nums[begin], nums[begin + 1]);
        int ans = i_1;
        for (int i = begin + 2; i <= end; i++)
        {
            ans = max(i_2 + nums[i], i_1);
            i_2 = i_1;
            i_1 = ans;
        }
        return ans;
    }
};
// @lc code=end
