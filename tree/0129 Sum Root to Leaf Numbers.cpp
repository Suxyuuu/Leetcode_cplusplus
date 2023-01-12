/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sum;
    int ans;
    int sumNumbers(TreeNode *root)
    {
        dfs(root);
        return ans;
    }

    void dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        sum = sum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            ans += sum;
        }
        dfs(root->left);
        dfs(root->right);
        sum = (sum - root->val) / 10;
    }
};
// @lc code=end
