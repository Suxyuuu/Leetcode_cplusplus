/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }
        stack<ListNode *> s1;
        stack<ListNode *> s2;

        // ListNode *dummy = new ListNode(-1);
        ListNode *cur = nullptr;
        // stack<ListNode> s_ans;
        while (l1 != nullptr)
        {
            s1.push(l1);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            s2.push(l2);
            l2 = l2->next;
        }
        int offset = 0;
        int sum = 0;
        while (!s1.empty() && !s2.empty())
        {
            ListNode *temp1 = s1.top();
            s1.pop();
            ListNode *temp2 = s2.top();
            s2.pop();
            sum = (temp1->val + temp2->val + offset) % 10;
            offset = (temp1->val + temp2->val + offset) / 10;
            ListNode *add = new ListNode(sum);

            add->next = cur;
            // dummy->next = add;
            cur = add;
        }
        while (!s1.empty())
        {
            ListNode *temp = s1.top();
            sum = (temp->val + offset) % 10;
            offset = (temp->val + offset) / 10;
            temp->val = sum;
            s1.pop();

            temp->next = cur;
            // dummy->next = temp;
            cur = temp;
        }
        while (!s2.empty())
        {
            ListNode *temp = s2.top();
            sum = (temp->val + offset) % 10;
            offset = (temp->val + offset) / 10;
            temp->val = sum;
            s2.pop();

            temp->next = cur;
            // dummy->next = temp;
            cur = temp;
        }
        if (offset != 0)
        {
            ListNode *temp = new ListNode(1);

            temp->next = cur;
            // dummy->next = temp;
            cur = temp;
        }

        return cur;
    }
};
// @lc code=end
