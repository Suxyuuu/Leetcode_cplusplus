/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] Mini Parser
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution
{
public:
    NestedInteger deserialize(string s)
    {
        if (s[0] != '[')
        {
            return NestedInteger(stoi(s));
        }
        stack<NestedInteger> sN;
        string str;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
            {
                sN.push(NestedInteger());
            }
            else if (s[i] == ',')
            {
                if (!str.empty())
                {
                    sN.top().add(NestedInteger(stoi(str)));
                }
                str.clear();
            }
            else if (s[i] == ']')
            {
                if (!str.empty())
                {
                    sN.top().add(NestedInteger(stoi(str)));
                    str.clear();
                }
                if (sN.size() > 1)
                {
                    NestedInteger cur = sN.top();
                    sN.pop();
                    sN.top().add(cur);
                }
            }
            else
            {
                str += s[i];
            }
        }
        return sN.top();
    }
};
// @lc code=end
