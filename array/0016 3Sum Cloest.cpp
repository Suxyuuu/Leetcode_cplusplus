class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[2];

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < n; i++)
        {
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                int temp = nums[left] + nums[right] + nums[i];
                if (temp > target)
                {
                    right--;
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
                else if (temp < target)
                {
                    left++;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                }
                else
                {
                    return temp;
                }
                ans = abs(temp - target) < abs(ans - target) ? temp : ans;
            }
        }
        return ans;
    }
};