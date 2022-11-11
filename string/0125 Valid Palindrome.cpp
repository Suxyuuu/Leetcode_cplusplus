/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int len = s.size();
        int i = 0, j = len - 1;
        while (i < j)
        {
            while (i < j && !isalpha(s[i]) && !isdigit(s[i]))
            {
                i++;
            }
            while (i < j && !isalpha(s[j]) && !isdigit(s[j]))
            {
                j--;
            }
            s[i] = tolower(s[i]);
            s[j] = tolower(s[j]);
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
// @lc code=end
