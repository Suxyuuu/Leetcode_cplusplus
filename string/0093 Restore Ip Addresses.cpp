/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] Restore IP Addresses
 */

// @lc code=start
class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        int len = s.size();
        if (len < 4)
        {
            return {};
        }

        vector<string> ans;
        vector<int> segments;

        trackback(s, 0, segments, ans);

        return ans;
    }

    void trackback(const string &s, int cur, vector<int> &segments, vector<string> &ans)
    {
        if (segments.size() == 3)
        {
            int num;
            if (isValid(s, cur, s.size() - 1, num))
            {
                string temp;
                for (auto &&seg : segments)
                {
                    temp += to_string(seg) + '.';
                }
                temp += to_string(num);
                ans.push_back(temp);
            }
            return;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                if (cur + i < s.size())
                {
                    int num;
                    if (isValid(s, cur, cur + i, num))
                    {
                        segments.push_back(num);
                        trackback(s, cur + i + 1, segments, ans);
                        segments.pop_back();
                    }
                }
            }
            return;
        }
    }

    bool isValid(const string &s, int begin, int end, int &num)
    {
        if (begin > end || end - begin > 2)
        {
            return false;
        }
        if (s[begin] == '0' && begin != end)
        {
            return false;
        }
        num = 0;
        for (int i = begin; i <= end; i++)
        {
            num = num * 10 + s[i] - '0';
        }
        if (num > 255)
        {
            return false;
        }
        return true;
    }
};
// @lc code=end
