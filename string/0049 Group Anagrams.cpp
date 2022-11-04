/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
// @lc code=end
