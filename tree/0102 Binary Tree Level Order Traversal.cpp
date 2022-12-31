/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<int> one_level;
        vector<vector<int>> result;
        queue<TreeNode *> first;
        queue<TreeNode *> second;
        TreeNode *cur = nullptr;
        int which_queue = 1;

        first.push(root);

        while (!first.empty() || !second.empty())
        {
            if (which_queue == 1)
            {
                cur = first.front();
                first.pop();
                one_level.emplace_back(cur->val);
                if (cur->left != nullptr)
                {
                    second.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    second.push(cur->right);
                }

                if (first.empty())
                {
                    which_queue = 2;
                    result.emplace_back(one_level);
                    one_level.clear();
                }
            }
            else
            {
                cur = second.front();
                second.pop();
                one_level.emplace_back(cur->val);
                if (cur->left != nullptr)
                {
                    first.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    first.push(cur->right);
                }

                if (second.empty())
                {
                    which_queue = 1;
                    result.emplace_back(one_level);
                    one_level.clear();
                }
            }
        }
        return result;
    }
};
// @lc code=end
