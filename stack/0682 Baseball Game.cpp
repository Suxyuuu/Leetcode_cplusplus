/*
 * @lc app=leetcode.cn id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        int get = 0;
        int sum = 0;
        stack<int> stk;
        for (auto &&op : operations)
        {
            if (op[0] == 'C')
            {
                int temp = stk.top();
                sum = sum - temp;
                stk.pop();
                get = stk.empty() ? 0 : stk.top();
            }
            else if (op[0] == 'D')
            {
                get = get + get;
                sum = sum + get;
                stk.push(get);
            }
            else if (op[0] == '+')
            {
                int pre1 = stk.top();
                stk.pop();
                int pre2 = stk.top();
                get = pre1 + pre2;
                sum = sum + get;
                stk.push(pre1);
                stk.push(get);
            }
            else
            {
                get = stoi(op);
                sum = sum + get;
                stk.push(get);
            }
        }
        return sum;
    }
};
// @lc code=end
