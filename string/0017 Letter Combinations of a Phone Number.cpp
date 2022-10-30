/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution
{
public:
    string temp;
    vector<string> ans;
    vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(int pos, string digits)
    {
        if (pos == digits.size())
        {
            ans.emplace_back(temp);
            return;
        }
        int num = digits[pos] - '0';
        for (int i = 0; i < map[num].size(); i++)
        {
            temp.push_back(map[num][i]);
            dfs(pos + 1, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
            return ans;
        dfs(0, digits);
        return ans;
    }
};
// @lc code=end
