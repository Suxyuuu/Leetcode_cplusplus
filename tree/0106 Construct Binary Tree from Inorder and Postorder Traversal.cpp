/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return help(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }

    TreeNode *help(vector<int> &inorder, vector<int> &postorder, int in_l, int in_r, int post_l, int post_r)
    {
        if (in_l > in_r || post_l > post_r)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(postorder[post_r]);
        int index = -1;
        for (int i = in_l; i <= in_r; i++)
        {
            if (inorder[i] == postorder[post_r])
            {
                index = i;
                break;
            }
        }
        int len = in_r - index;
        root->left = help(inorder, postorder, in_l, index - 1, post_l, post_r - 1 - len);
        root->right = help(inorder, postorder, index + 1, in_r, post_r - len, post_r - 1);
        return root;
    }
};
// @lc code=end
