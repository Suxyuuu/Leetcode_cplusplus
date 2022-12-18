/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0 || len == 1)
        {
            return 0;
        }
        if (len == 2)
        {
            return nums[0] <= nums[1] ? 0 : 2;
        }

        int left = -1;
        int right = -1;
        int min_num = 0;
        int max_num = 0;
        for (int i = 1; i < len; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                left = i - 1;
                break;
            }
        }
        if (left == -1)
        {
            return 0;
        }

        for (int i = len - 2; i >= 0; i--)
        {
            if (nums[i] > nums[i + 1])
            {
                right = i + 1;
                break;
            }
        }
        min_num = nums[left];
        max_num = nums[right];
        for (int i = left; i <= right; i++)
        {
            min_num = min(nums[i], min_num);
            max_num = max(nums[i], max_num);
        }

        while (left >= 1)
        {
            if (nums[left - 1] > min_num)
            {
                left--;
            }
            else
            {
                break;
            }
        }
        while (right <= len - 2)
        {
            if (nums[right + 1] < max_num)
            {
                right++;
            }
            else
            {
                break;
            }
        }

        return right - left + 1;
    }
};
// @lc code=end
