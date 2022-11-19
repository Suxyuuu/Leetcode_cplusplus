/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *dummy = new ListNode(-1, head);
        ListNode *cur = head->next;
        ListNode *reverse_head = dummy;
        ListNode *reverse_tail = head;
        while (cur != nullptr)
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
