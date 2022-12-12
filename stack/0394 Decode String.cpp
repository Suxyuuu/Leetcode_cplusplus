/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        string ans;
        stack<string> s_ans;
        stack<int> s_times;
        int times = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                times = times * 10 + s[i] - '0';
            }
            else if (s[i] == '[')
            {
                s_times.push(times);
                times = 0;
                s_ans.push(ans);
                ans.clear();
            }
            else if (isalpha(s[i]))
            {
                ans += s[i];
            }
            else
            {
                times = s_times.top();
                s_times.pop();
                string temp_ans = s_ans.top();
                s_ans.pop();
                for (int i = 0; i < times; i++)
                {
                    temp_ans += ans;
                }
                times = 0;
                ans = temp_ans;
            }
        }
        return ans;
    }
};
// @lc code=end
