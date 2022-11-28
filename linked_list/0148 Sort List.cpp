/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        int len = 0;
        ListNode *node = head;
        while (node != nullptr)
        {
            len++;
            node = node->next;
        }
        ListNode *dummy = new ListNode(-1, head);

        for (int sublen = 1; sublen < len; sublen <<= 1)
        {
            ListNode *pre = dummy;
            ListNode *cur = dummy->next;
            while (cur != nullptr)
            {
                ListNode *subList1 = cur;
                for (int i = 1; i < sublen && cur->next != nullptr; i++)
                {
                    cur = cur->next;
                }
                ListNode *subList2 = cur->next;
                cur->next = nullptr;
                cur = subList2;
                for (int i = 1; i < sublen && cur != nullptr && cur->next != nullptr; i++)
                {
                    cur = cur->next;
                }
                ListNode *temp = nullptr;
                if (cur != nullptr)
                {
                    temp = cur->next;
                    cur->next = nullptr;
                }

                ListNode *merged = merge(subList1, subList2);
                pre->next = merged;
                while (pre->next != nullptr)
                {
                    pre = pre->next;
                }
                cur = temp;
            }
        }
        return dummy->next;
    }

    ListNode *merge(ListNode *L1, ListNode *L2)
    {
        if (L1 == nullptr)
        {
            return L2;
        }
        if (L2 == nullptr)
        {
            return L1;
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;

        while (L1 != nullptr && L2 != nullptr)
        {
            if (L1->val <= L2->val)
            {
                cur->next = L1;
                L1 = L1->next;
            }
            else
            {
                cur->next = L2;
                L2 = L2->next;
            }
            cur = cur->next;
        }
        if (L1 == nullptr)
        {
            cur->next = L2;
        }
        else
        {
            cur->next = L1;
        }
        return dummy->next;
    }
};
// @lc code=end
