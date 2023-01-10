/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        dfs(root, targetSum);
        return res;
    }

    void dfs(TreeNode *root, int targetSum)
    {
        if (root == nullptr)
        {
            return;
        }

        targetSum -= root->val;
        path.emplace_back(root->val);
        if (root->left == nullptr && root->right == nullptr && targetSum == 0)
        {
            res.emplace_back(path);
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        path.pop_back();
    }
};
// @lc code=end
