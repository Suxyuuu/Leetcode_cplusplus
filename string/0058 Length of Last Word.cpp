/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = s.size();
        if (len == 0)
        {
            return 0;
        }
        int ans = 0;
        int i = len - 1;
        while (i >= 0)
        {
            if (s[i] != ' ')
                break;
            i--;
        }
        while (i >= 0)
        {
            if (s[i] != ' ')
            {
                ans++;
            }
            else
            {
                break;
            }
            i--;
        }
        return ans;
    }
};
// @lc code=end
