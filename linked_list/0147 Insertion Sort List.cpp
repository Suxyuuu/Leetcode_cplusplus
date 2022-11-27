/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *dummy = new ListNode(-6000);
        ListNode *cur = head;
        ListNode *pre = nullptr;
        ListNode *find = dummy;
        while (cur != nullptr)
        {
            ListNode *temp = cur;
            cur = cur->next;
            temp->next = nullptr;
            if (cur == head)
            {
                continue;
            }
            else
            {
                pre = nullptr;
                find = dummy;
                while (find != nullptr)
                {
                    if (find->val >= temp->val)
                    {
                        break;
                    }
                    else
                    {
                        pre = find;
                        find = find->next;
                    }
                }
                pre->next = temp;
                temp->next = find;
            }
        }
        return dummy->next;
    }
};
// @lc code=end
