/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    string path;
    vector<string> ans;

    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (root == nullptr)
        {
            return ans;
        }

        dfs(root);
        return ans;
    }

    void dfs(TreeNode *root)
    {
        string num = to_string(root->val);
        path += num;
        int len = num.size();

        if (root->left == nullptr && root->right == nullptr)
        {
            ans.emplace_back(path);
            for (int i = 0; i < len; i++)
            {
                path.pop_back();
            }
            return;
        }

        if (root->left != nullptr)
        {
            path += "->";
            dfs(root->left);
            path.pop_back();
            path.pop_back();
        }

        if (root->right != nullptr)
        {
            path += "->";
            dfs(root->right);
            path.pop_back();
            path.pop_back();
        }

        for (int i = 0; i < len; i++)
        {
            path.pop_back();
        }
        
    }
};
// @lc code=end
