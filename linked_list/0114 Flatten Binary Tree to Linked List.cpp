/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return;
        }

        stack<TreeNode *> s;
        TreeNode *pre = nullptr;
        s.push(root);

        while (!s.empty())
        {
            TreeNode *cur = s.top();
            s.pop();
            if (pre != nullptr)
            {
                pre->left = nullptr;
                pre->right = cur;
            }
            if (cur->right != nullptr)
            {
                s.push(cur->right);
            }
            if (cur->left != nullptr)
            {
                s.push(cur->left);
            }
            pre = cur;
        }
    }
};
// @lc code=end
