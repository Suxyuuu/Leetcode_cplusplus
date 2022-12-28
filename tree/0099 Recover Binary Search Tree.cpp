/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    TreeNode *w1, *w2, *pre;
    void recoverTree(TreeNode *root)
    {
        travel(root);
        swap(w1->val, w2->val);
        return;
    }

    void travel(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        travel(root->left);
        if (pre != nullptr && root->val < pre->val)
        {
            if (w1 == nullptr)
            {
                w1 = pre;
            }
            w2 = root;
        }
        pre = root;
        travel(root->right);
        return;
    }
};
// @lc code=end
