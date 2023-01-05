/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }

        vector<int> level;
        queue<TreeNode *> one;
        queue<TreeNode *> two;
        stack<vector<int>> st;
        vector<vector<int>> result;
        int flag = 1;

        one.push(root);

        while (!one.empty() || !two.empty())
        {
            if (flag == 1)
            {
                TreeNode *cur = one.front();
                one.pop();
                level.emplace_back(cur->val);
                if (cur->left != nullptr)
                {
                    two.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    two.push(cur->right);
                }
                if (one.empty())
                {
                    st.push(level);
                    level.clear();
                    flag = 2;
                }
            }
            else
            {
                TreeNode *cur = two.front();
                two.pop();
                level.emplace_back(cur->val);
                if (cur->left != nullptr)
                {
                    one.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    one.push(cur->right);
                }
                if (two.empty())
                {
                    st.push(level);
                    level.clear();
                    flag = 1;
                }
            }
        }
        while (!st.empty())
        {
            vector<int> temp = st.top();
            st.pop();
            result.emplace_back(temp);
        }
        return result;
    }
};
// @lc code=end
