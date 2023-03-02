/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution
{
public:
    bool makesquare(vector<int> &matchsticks)
    {
        if (matchsticks.size() == 0)
        {
            return false;
        }
        int sum = 0;
        for (int i = 0; i < matchsticks.size(); i++)
        {
            sum += matchsticks[i];
        }
        if (sum % 4 != 0)
        {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int target = sum / 4;
        return dfs(matchsticks, 0, target, 0, 0, 0, 0);
    }

    bool dfs(vector<int> &matchsticks, int curpos, int target, int n1, int n2, int n3, int n4)
    {
        if (curpos == matchsticks.size())
        {
            return n1 == target && n2 == target && n3 == target && n4 == target;
        }

        if (n1 > target || n2 > target || n3 > target || n4 > target)
        {
            return false;
        }

        return dfs(matchsticks, curpos + 1, target, n1 + matchsticks[curpos], n2, n3, n4) ||
               dfs(matchsticks, curpos + 1, target, n1, n2 + matchsticks[curpos], n3, n4) ||
               dfs(matchsticks, curpos + 1, target, n1, n2, n3 + matchsticks[curpos], n4) ||
               dfs(matchsticks, curpos + 1, target, n1, n2, n3, n4 + matchsticks[curpos]);
    }
};
// @lc code=end
