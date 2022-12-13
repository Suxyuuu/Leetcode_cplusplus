/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] Remove K Digits
 */

// @lc code=start
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        vector<char> s;
        for (auto &&ch : num)
        {
            if (s.empty())
            {
                s.emplace_back(ch);
            }
            else
            {
                if (k == 0)
                {
                    s.emplace_back(ch);
                    continue;
                }
                char temp = s.back();
                if (ch >= temp)
                {
                    s.emplace_back(ch);
                }
                else
                {
                    while (!s.empty() && s.back() > ch && k > 0)
                    {
                        s.pop_back();
                        k--;
                    }
                    s.emplace_back(ch);
                }
            }
        }
        while (k != 0)
        {
            s.pop_back();
            k--;
        }

        string ans;
        bool isLeadingZero = true;
        for (auto &&ch : s)
        {
            if (ch == '0' && isLeadingZero)
            {
                continue;
            }
            isLeadingZero = false;
            ans += ch;
        }
        return ans == "" ? "0" : ans;
    }
};
// @lc code=end
