/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] House Robber III
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
    unordered_map<TreeNode *, int> robbed;
    unordered_map<TreeNode *, int> unrob;

    int rob(TreeNode *root)
    {
        dfs(root);
        return max(robbed[root], unrob[root]);
    }

    void dfs(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        robbed[node] = node->val + unrob[node->left] + unrob[node->right];
        unrob[node] = max(robbed[node->left], unrob[node->left]) + max(robbed[node->right], unrob[node->right]);
    }
};
// @lc code=end
