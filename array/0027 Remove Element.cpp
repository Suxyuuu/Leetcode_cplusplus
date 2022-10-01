class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        int slow = 0;
        while (slow < len)
        {
            if (nums[slow] == val)
                break;
            else
                slow++;
        }
        if (slow == len)
            return len;
        int fast = slow + 1;
        while (fast < len)
        {
            if (nums[fast] != val)
            {
                nums[slow] = nums[fast];
                slow++;
            }

            fast++;
        }
        return slow;
    }
};