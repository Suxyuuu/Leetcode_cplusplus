/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
        {
            return root;
        }
        queue<pair<Node *, int>> q;
        q.push(make_pair(root, 1));
        while (!q.empty())
        {
            Node *cur = q.front().first;
            int level = q.front().second;
            q.pop();
            if (q.empty())
            {
                cur->next = nullptr;
            }
            else
            {
                Node *temp = q.front().first;
                if (level == q.front().second)
                {
                    cur->next = temp;
                }
                else
                {
                    cur->next = nullptr;
                }
            }
            if (cur->left != nullptr)
            {
                q.push(make_pair(cur->left, level + 1));
                q.push(make_pair(cur->right, level + 1));
            }
        }
        return root;
    }
};
// @lc code=end
