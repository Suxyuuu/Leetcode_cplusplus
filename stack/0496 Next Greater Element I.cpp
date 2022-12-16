/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int len = nums2.size();
        // vector<int> nge_array(len);
        unordered_map<int, int> nge_map;
        stack<int> st;

        for (int i = len - 1; i >= 0; i--)
        {
            while (!st.empty() && nums2[st.top()] <= nums2[i])
            {
                st.pop();
            }
            nge_map[nums2[i]] = st.empty() ? -1 : nums2[st.top()];
            // nge_array[i] = st.empty()? -1 : nums2[st.top()];
            st.push(i);
        }

        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            result[i] = nge_map[nums1[i]];
        }
        return result;
    }
};
// @lc code=end
