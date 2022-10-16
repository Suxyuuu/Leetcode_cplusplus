class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 1)
            return true;
        int canjump = 0;

        for (int i = 0; i < len - 1; i++)
        {
            if (i <= canjump)
            {
                canjump = max(canjump, i + nums[i]);
                if (canjump >= len - 1)
                {
                    return true;
                }
            }
            else
            {
                break;
            }
        }
        return false;
    }
};