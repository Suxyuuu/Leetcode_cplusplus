/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = head;
        ListNode *pre = dummy;
        while (cur->next != nullptr)
        {
            while (cur->next != nullptr && cur->val == cur->next->val)
            {
                cur = cur->next;
            }
            if (cur->next == nullptr)
            {
                pre->next = nullptr;
                break;
            }

            if (pre->next == cur)
            {
                pre = cur;
                cur = cur->next;
            }
            else
            {
                pre->next = cur->next;
                cur = pre->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end
