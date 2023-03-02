/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        Node *cur = head;
        while (cur != nullptr)
        {
            Node *copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }
        cur = head->next;
        Node *pre = head;
        while (cur != nullptr)
        {
            if (pre->random == nullptr)
            {
                cur->random = nullptr;
            }
            else
            {
                cur->random = pre->random->next;
            }
            pre = cur->next;
            if (pre != nullptr)
            {
                cur = pre->next;
            }
            else
            {
                cur = nullptr;
            }
        }
        pre = head;
        Node *ans = head->next;
        cur = pre->next;
        while (cur != nullptr)
        {
            pre->next = cur->next;
            pre = cur;
            cur = pre->next;
        }
        return ans;
    }
};
// @lc code=end
