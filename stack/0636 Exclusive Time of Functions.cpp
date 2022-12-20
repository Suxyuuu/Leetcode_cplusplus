/*
 * @lc app=leetcode.cn id=636 lang=cpp
 *
 * [636] Exclusive Time of Functions
 */

// @lc code=start
class Solution
{
public:
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        stack<pair<int, int>> stk; // pair<first:idx, second:startTime>
        vector<int> res(n, 0);
        for (const auto &log : logs)
        {
            char type[10];
            int idx, timestamp;
            // c_str转换成char数组来读取，后面“”部分为读取格式，%[^:]表示读取到:停止
            sscanf(log.c_str(), "%d:%[^:]:%d", &idx, type, &timestamp);
            if (type[0] == 's')
            {
                if (!stk.empty())
                {
                    res[stk.top().first] += timestamp - stk.top().second;
                    stk.top().second = timestamp;
                }
                stk.emplace(idx, timestamp);
            }
            else
            {
                auto t = stk.top();
                stk.pop();
                res[t.first] += timestamp - t.second + 1;
                if (!stk.empty())
                {
                    stk.top().second = timestamp + 1;
                }
            }
        }
        return res;
    }
};
// @lc code=end
