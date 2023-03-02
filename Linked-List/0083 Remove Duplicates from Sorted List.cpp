/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
        ListNode *cur = head;
        ListNode *pre = head;
        while (cur != nullptr)
        {
            while (cur != nullptr && cur->val == pre->val)
            {
                cur = cur->next;
            }
            if (cur == nullptr)
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
                pre->next = cur;
                pre = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end
