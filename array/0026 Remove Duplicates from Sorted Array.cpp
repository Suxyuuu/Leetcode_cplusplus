class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int slow = 0;
        int fast = 0;
        while (fast < n)
        {
            if (nums[fast] == nums[slow])
            {
                fast++;
            }
            else
            {
                nums[slow + 1] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow + 1;
    }
};