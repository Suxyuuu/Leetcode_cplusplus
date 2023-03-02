/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return;
        }
        // get middle node
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *reverse = new ListNode(-1);
        pre->next = nullptr;

        // reverse tail
        while (slow != nullptr)
        {
            ListNode *temp = slow->next;
            slow->next = reverse->next;
            reverse->next = slow;
            slow = temp;
        }

        // merge two linked list
        slow = reverse->next; // reverse list
        fast = head;          // ordered list
        while (slow != nullptr && fast->next != nullptr)
        {
            ListNode *temp = slow->next;
            slow->next = fast->next;
            fast->next = slow;
            slow = temp;
            fast = fast->next->next;
        }

        if (fast->next == nullptr)
        {
            fast->next = slow;
        }
    }
};
// @lc code=end
