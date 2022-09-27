class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return {};
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                return ans;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                if (nums[left] + nums[right] > -nums[i])
                {
                    right--;
                }
                else if (nums[left] + nums[right] < -nums[i])
                {
                    left++;
                }
                else
                {
                    ans.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                    {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};