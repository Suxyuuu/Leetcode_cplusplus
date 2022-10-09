class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return 0;
        vector<int> jump(len, 9999);
        jump[0] = 0;
        for (size_t i = 0; i < len; i++)
        {
            for (size_t j = 1; j <= nums[i]; j++)
            {
                jump[i + j] = min(jump[i + j], jump[i] + 1);
                if (i + j == len - 1)
                    return jump[len - 1];
            }
        }
        return jump[len - 1];
    }
};