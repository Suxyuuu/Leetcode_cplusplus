/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
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
class Solution {
public:
    queue<TreeNode *> one;
    queue<TreeNode *> two;
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr)
        {
            return {};
        }
        int flag = 1;
        one.push(root);
        while (!one.empty() || !two.empty())
        {
            if (flag == 1)
            {
                TreeNode *cur = one.front();
                if (one.size() == 1)
                {
                    ans.emplace_back(cur->val);
                }
                one.pop();
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
                    flag = 2;    
                }
            }
            else
            {
                TreeNode *cur = two.front();
                if (two.size() == 1)
                {
                    ans.emplace_back(cur->val);
                }
                two.pop();
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
                    flag = 1;    
                }
            }
        }
        return ans;
    }
};
// @lc code=end

