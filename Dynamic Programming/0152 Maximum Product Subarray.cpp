/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }

        int ans = nums[0];
        int max_num = nums[0];
        int min_num = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < 0)
            {
                swap(max_num, min_num);
            }
            max_num = max(nums[i], max_num * nums[i]);
            min_num = min(nums[i], min_num * nums[i]);
            ans = max(ans, max_num);
        }
        return ans;
    }
};
// @lc code=end
