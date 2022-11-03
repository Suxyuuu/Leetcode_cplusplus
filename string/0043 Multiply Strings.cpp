/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        int m = num1.size();
        int n = num2.size();
        vector<int> temp(m + n);
        for (int i = m - 1; i >= 0; i--)
        {
            int x = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--)
            {
                int y = num2[j] - '0';
                temp[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--)
        {
            temp[i - 1] += temp[i] / 10;
            temp[i] %= 10;
        }

        string ans;

        int index = temp[0] == 0 ? 1 : 0;
        for (; index < m + n; index++)
        {
            ans += '0' + temp[index];
        }
        return ans;
    }
};
// @lc code=end
