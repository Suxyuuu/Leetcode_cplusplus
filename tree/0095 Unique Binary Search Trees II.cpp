/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
        {
            return {};
        }

        return fun(1, n);
    }

    vector<TreeNode *> fun(int l, int r)
    {
        if (l > r)
        {
            return {nullptr};
        }

        vector<TreeNode *> res;

        for (int i = l; i <= r; i++)
        {
            vector<TreeNode *> vec_left = fun(l, i - 1);
            vector<TreeNode *> vec_right = fun(i + 1, r);

            for (auto &&left : vec_left)
            {
                for (auto &&right : vec_right)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = left;
                    node->right = right;
                    res.emplace_back(node);
                }
            }
        }
        return res;
    }
};
// @lc code=end
