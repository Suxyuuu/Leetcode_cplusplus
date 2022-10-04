class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int len = nums.size();
        if (len == 0)
            return {-1, -1};
        if (len == 1)
            return nums[0] == target ? vector<int>{0, 0} : vector<int>{-1, -1};
        return {findFirst(nums, target), findLast(nums, target)};
    }

    int findFirst(vector<int> &nums, int target)
    {
        int len = nums.size();
        int left = 0, right = len - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                if (mid == 0 || nums[mid - 1] != target)
                {
                    return mid;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }

    int findLast(vector<int> &nums, int target)
    {
        int len = nums.size();
        int left = 0, right = len - 1;
        while (left <= right)
        {
            int mid = (left + right) >> 1;
            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                if (mid == len - 1 || nums[mid + 1] != target)
                {
                    return mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};