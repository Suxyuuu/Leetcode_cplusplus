/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */

// @lc code=start
class Solution
{
public:
    int ans;
    string cur_str;
    unordered_set<int> not_unique;

    int maxLength(vector<string> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (!only_unique(arr[i]))
            {
                not_unique.insert(i);
            }
        }
        
        dfs(0, arr);
        return ans;
    }

    void dfs(int curpos, vector<string> &arr)
    {
        if (curpos == arr.size())
        {
            ans = max(ans, int(cur_str.size()));
            return;
        }

        if (not_unique.count(curpos))
        {
            dfs(curpos + 1, arr);
        }
        else if (both_unique(cur_str, arr[curpos]))
        {
            cur_str += arr[curpos];
            dfs(curpos + 1, arr);
            for (size_t i = 0; i < arr[curpos].size(); i++)
            {
                cur_str.pop_back();
            }
            dfs(curpos + 1, arr);
        }
        else
        {
            dfs(curpos + 1, arr);
        }
    }

    bool only_unique(string &a)
    {
        int s[26] = {};
        for (auto &&ch : a)
        {
            if (s[ch - 'a'] == 1)
            {
                return false;
            }
            s[ch - 'a'] = 1;
        }
        return true;
    }

    bool both_unique(string &a, string &b)
    {
        for (auto &&cha : a)
        {
            for (auto &&chb : b)
            {
                if (cha == chb)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
