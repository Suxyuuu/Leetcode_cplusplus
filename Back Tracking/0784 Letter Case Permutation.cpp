/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
class Solution
{
public:
    vector<string> ans;
    string path;

    vector<string> letterCasePermutation(string s)
    {
        dfs(0, s);
        return ans;
    }

    void dfs(int curpos, const string &s)
    {
        if (curpos == s.size())
        {
            ans.emplace_back(path);
            return;
        }
        if (!isalpha(s[curpos]))
        {
            path += s[curpos];
            dfs(curpos + 1, s);
            path.pop_back();
        }
        else
        {
            char ch = s[curpos];
            path += tolower(ch);
            dfs(curpos + 1, s);
            path[path.size() - 1] = toupper(ch);
            dfs(curpos + 1, s);
            path.pop_back();
        }
    }
};
// @lc code=end
