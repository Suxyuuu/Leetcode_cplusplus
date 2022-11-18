/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode *partition(ListNode *head, int x)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *small_head = nullptr;
        ListNode *small_tail = nullptr;
        ListNode *big_head = nullptr;
        ListNode *big_tail = nullptr;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            if (small_head == nullptr && cur->val < x)
            {
                small_head = small_tail = cur;
            }
            else if (big_head == nullptr && cur->val >= x)
            {
                big_head = big_tail = cur;
            }
            else
            {
                if (cur->val >= x)
                {
                    big_tail->next = cur;
                    big_tail = cur;
                }
                else
                {
                    small_tail->next = cur;
                    small_tail = cur;
                }
            }
            cur = cur->next;
        }
        if (small_head == nullptr || big_head == nullptr)
        {
            return head;
        }

        small_tail->next = big_head;
        big_tail->next = nullptr;
        return small_head;
    }
};
// @lc code=end
