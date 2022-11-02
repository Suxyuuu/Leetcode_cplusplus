/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int h_len = haystack.size();
        if (h_len == 0)
        {
            return -1;
        }
        int n_len = needle.size();
        for (int i = 0; i < h_len; i++)
        {
            for (int j = 0; j <= n_len; j++)
            {
                if (j == n_len)
                {
                    return i;
                }
                if (i + j > h_len)
                {
                    return -1;
                }
                if (needle[j] != haystack[i + j])
                {
                    break;
                }
            }
        }
        return -1;
    }
};
// @lc code=end
