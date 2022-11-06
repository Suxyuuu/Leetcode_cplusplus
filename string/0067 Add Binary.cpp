/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        int m = a.size() - 1;
        int n = b.size() - 1;
        string ans;
        int carry = 0;

        while (m >= 0 && n >= 0)
        {
            int sum = carry;
            sum += a[m--] - '0';
            sum += b[n--] - '0';
            carry = sum / 2;
            ans += sum % 2 + '0';
        }
        while (m >= 0)
        {
            int sum = carry;
            sum += a[m--] - '0';
            carry = sum / 2;
            ans += sum % 2 + '0';
        }
        while (n >= 0)
        {
            int sum = carry;
            sum += b[n--] - '0';
            carry = sum / 2;
            ans += sum % 2 + '0';
        }
        if (carry == 1)
        {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
// @lc code=end
