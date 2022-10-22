/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int len = digits.size();
        bool flag = false;
        for (int i = len - 1; i >= 0; i--)
        {
            if (!flag)
            {
                if (digits[i] != 9)
                {
                    digits[i]++;
                    flag = false;
                    break;
                }
                else
                {
                    digits[i] = 0;
                    flag = true;
                }
            }
            else
            {
                if (digits[i] == 9)
                {
                    digits[i] = 0;
                    flag = true;
                }
                else
                {
                    digits[i]++;
                    flag = false;
                    break;
                }
            }
        }
        if (flag)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
// @lc code=end
