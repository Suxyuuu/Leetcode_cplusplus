/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution
{
public:
    // 直接计算卡特兰数会溢出 使用相邻卡特兰数之间的关系进行迭代
    int numTrees(int n)
    {
        long long C = 1;
        for (int i = 0; i < n; ++i)
        {
            C = C * 2 * (2 * i + 1) / (i + 2);
        }
        return (int)C;
    }
};
// @lc code=end
