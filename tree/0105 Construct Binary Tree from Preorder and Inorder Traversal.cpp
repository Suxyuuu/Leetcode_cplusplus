/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return help(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *help(vector<int> &preorder, vector<int> &inorder, int pre_l, int pre_r, int in_l, int in_r)
    {
        if (pre_l > pre_r || in_l > in_r)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[pre_l]);
        int index = -1;
        for (int i = in_l; i <= in_r; i++)
        {
            if (preorder[pre_l] == inorder[i])
            {
                index = i;
                break;
            }
        }
        int len = index - in_l;
        root->left = help(preorder, inorder, pre_l + 1, pre_l + len, in_l, index - 1);
        root->right = help(preorder, inorder, pre_l + len + 1, pre_r, index + 1, in_r);
        return root;
    }
};
// @lc code=end
