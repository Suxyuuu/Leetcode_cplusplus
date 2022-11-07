/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        auto split = [](string &s, char c) -> vector<string>
        {
            vector<string> ans;
            string temp;
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == c)
                {
                    ans.push_back(temp);
                    temp.clear();
                }
                else
                {
                    temp += s[i];
                }
            }
            ans.push_back(temp);
            return ans;
        };

        vector<string> folders = split(path, '/');
        vector<string> st;
        for (auto &&folder : folders)
        {
            if (folder == "..")
            {
                if (!st.empty())
                {
                    st.pop_back();
                }
            }
            else
            {
                if (folder != "" && folder != ".")
                {
                    st.push_back(folder);
                }
            }
        }
        string ans;
        if (st.empty())
        {
            return "/";
        }
        else
        {
            for (auto &&str : st)
            {
                ans += "/" + str;
            }
        }
        return ans;
    }
};
// @lc code=end
