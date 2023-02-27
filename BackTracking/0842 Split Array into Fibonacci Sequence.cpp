/*
 * @lc app=leetcode.cn id=842 lang=cpp
 *
 * [842] Split Array into Fibonacci Sequence
 */

// @lc code=start
class Solution
{
public:
    vector<int> splitIntoFibonacci(string num)
    {
        vector<int> list;
        backtrack(list, num, num.length(), 0, 0, 0);
        return list;
    }

    bool backtrack(vector<int> &list, string num, int length, int index, long long sum, int prev)
    {
        if (index == length)
        {
            return list.size() >= 3;
        }
        long long curr = 0;
        for (int i = index; i < length; i++)
        {
            if (i > index && num[index] == '0')
            {
                break;
            }
            curr = curr * 10 + num[i] - '0';
            if (curr > INT_MAX)
            {
                break;
            }
            if (list.size() >= 2)
            {
                if (curr < sum)
                {
                    continue;
                }
                else if (curr > sum)
                {
                    break;
                }
            }
            list.push_back(curr);
            if (backtrack(list, num, length, i + 1, prev + curr, curr))
            {
                return true;
            }
            list.pop_back();
        }
        return false;
    }
};
// @lc code=end
