/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> s1;
        stack<char> s2;
        for (auto &&ch : s)
        {
            if (ch == '#')
            {
                if (!s1.empty())
                {
                    s1.pop();
                }
            }
            else
            {
                s1.push(ch);
            }
        }
        for (auto &&ch : t)
        {
            if (ch == '#')
            {
                if (!s2.empty())
                {
                    s2.pop();
                }
            }
            else
            {
                s2.push(ch);
            }
        }
        if (s1.size() != s2.size())
        {
            return false;
        }
        else
        {
            int len = s1.size();
            for (int i = 0; i < len; i++)
            {
                if (s1.top() != s2.top())
                {
                    return false;
                }
                else
                {
                    s1.pop();
                    s2.pop();
                }
            }
            return true;
        }
    }
};
// @lc code=end
