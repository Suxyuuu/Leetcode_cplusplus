class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        if (n == 0)
            return {};
        string temp;
        vector<string> ans;
        dfs(n, n, temp, ans);
        return ans;
    }

    void dfs(int lnum, int rnum, string temp, vector<string> &ans)
    {
        if (lnum == rnum && lnum == 0)
        {
            ans.push_back(temp);
            return;
        }
        else
        {
            if (lnum > 0)
            {
                temp.push_back('(');
                dfs(lnum - 1, rnum, temp, ans);
                temp.pop_back();
            }
            if (rnum > 0 && lnum < rnum)
            {
                temp.push_back(')');
                dfs(lnum, rnum - 1, temp, ans);
                temp.pop_back();
            }
        }
    }
};