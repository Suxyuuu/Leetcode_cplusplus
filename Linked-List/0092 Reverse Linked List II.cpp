/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (head == nullptr || head->next == nullptr || left == right)
        {
            return head;
        }
        ListNode *reverse_head = nullptr;
        ListNode *reverse_tail = nullptr;
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = dummy;

        for (size_t i = 0; i < left - 1; i++)
        {
            cur = cur->next;
        }
        reverse_head = cur;
        cur = cur->next;
        reverse_tail = cur;
        cur = cur->next;
        for (size_t i = 0; i < right - left; i++)
        {
            ListNode *temp = cur->next;
            cur->next = reverse_head->next;
            reverse_head->next = cur;
            reverse_tail->next = temp;
            cur = temp;
        }
        return dummy->next;
    }
};
// @lc code=end
