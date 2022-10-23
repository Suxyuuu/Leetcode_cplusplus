/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.size();
        if (len == 0 || len == 1)
        {
            return len;
        }

        vector<bool> exist(128, false);
        int ans = 0;
        int left = 0;
        int right = 0;
        int cur = 0;

        while (right < len)
        {
            if (exist[s[right] - ' '] == false)
            {
                exist[s[right] - ' '] = true;
                right++;
                cur++;
            }
            else
            {
                ans = max(ans, cur);
                while (s[left] != s[right])
                {
                    exist[s[left] - ' '] = false;
                    left++;
                    cur--;
                }
                exist[s[left] - ' '] = false;
                left++;
                cur--;
            }
        }
        return max(ans, cur);
    }
};
// @lc code=end
