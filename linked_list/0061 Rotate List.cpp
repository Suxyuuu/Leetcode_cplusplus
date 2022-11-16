/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (k == 0)
        {
            return head;
        }
        if (head == nullptr)
        {
            return head;
        }

        ListNode *dummy = new ListNode(-1, head);
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        int len = 0;
        for (size_t i = 0; i < k; i++)
        {
            if (fast->next != nullptr)
            {
                fast = fast->next;
            }
            else
            {
                len = i;
                break;
            }
        }
        if (fast->next == nullptr && len != 0)
        {
            k = k % len;
            if (k == 0)
            {
                return head;
            }

            fast = dummy;
            for (size_t i = 0; i < k; i++)
            {
                fast = fast->next;
            }
        }

        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        if (slow == dummy)
        {
            return head;
        }

        fast->next = dummy->next;
        dummy->next = slow->next;
        slow->next = nullptr;

        return dummy->next;
    }
};
// @lc code=end
