/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sta;
        for (auto &&c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                sta.push(c);
            }
            else
            {
                if (c == ')')
                {
                    if (!sta.empty() && sta.top() == '(')
                    {
                        sta.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (c == ']')
                {
                    if (!sta.empty() && sta.top() == '[')
                    {
                        sta.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else if (c == '}')
                {
                    if (!sta.empty() && sta.top() == '{')
                    {
                        sta.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        if (sta.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
