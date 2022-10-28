/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

// @lc code=start

class Solution
{
private:
    unordered_map<char, int> Symbol2Value = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1},
    };

public:
    int romanToInt(string s)
    {
        int ans = 0;
        int value = 0;
        int prevalue = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            value = Symbol2Value[s[i]];
            if (value < prevalue)
            {
                ans -= value;
            }
            else
            {
                ans += value;
            }
            prevalue = value;
        }
        return ans;
    }
};
// @lc code=end
