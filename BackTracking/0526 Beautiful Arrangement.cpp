/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

// @lc code=start
class Solution
{
public:
    int ans = 0;
    vector<int> visited;
    int n = 0;

    int countArrangement(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        visited.resize(n, 0);
        this->n = n;
        dfs(0);
        return ans;
    }

    void dfs(int len)
    {
        if (len == this->n)
        {
            ans++;
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (visited[i - 1] == 0 && (i % (len + 1) == 0 || (len + 1) % i == 0))
            {
                visited[i - 1] = 1;
                len++;
                dfs(len);
                visited[i - 1] = 0;
                len--;
            }
        }
    }
};
// @lc code=end
