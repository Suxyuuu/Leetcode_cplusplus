/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] Daily Temperatures
 */

// @lc code=start
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int length = temperatures.size();
        if (length == 1)
        {
            return {0};
        }

        stack<int> stk;
        vector<int> res(length);

        for (int i = length - 1; i >= 0; i--)
        {
            if (stk.empty())
            {
                res[i] = 0;
                stk.push(i);
            }
            else
            {
                if (temperatures[i] < temperatures[stk.top()])
                {
                    res[i] = stk.top() - i;
                    stk.push(i);
                }
                else
                {
                    while (!stk.empty() && temperatures[i] >= temperatures[stk.top()])
                    {
                        stk.pop();
                    }
                    if (stk.empty())
                    {
                        res[i] = 0;
                    }
                    else
                    {
                        res[i] = stk.top() - i;
                    }
                    stk.push(i);
                }
            }
        }
        return res;
    }
};
// @lc code=end
