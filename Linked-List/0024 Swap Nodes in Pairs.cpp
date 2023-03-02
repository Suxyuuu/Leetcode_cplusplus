/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *dummy = new ListNode(-1, head);

        ListNode *cur = dummy;

        while (cur->next && cur->next->next)
        {
            swap2Nodes(cur);
            cur = cur->next->next;
        }
        return dummy->next;
    }

    void swap2Nodes(ListNode *before)
    {
        ListNode *n1 = before->next;
        ListNode *n2 = n1->next;

        before->next = n2;
        n1->next = n2->next;
        n2->next = n1;
    }
};
// @lc code=end
