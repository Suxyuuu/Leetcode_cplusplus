/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        Traversal(root, ans);
        return ans;
    }

    void Traversal(TreeNode *root, vector<int> &ans)
    {
        if (root == nullptr)
        {
            return;
        }

        Traversal(root->left, ans);
        Traversal(root->right, ans);
        ans.push_back(root->val);
    }
};
// @lc code=end
