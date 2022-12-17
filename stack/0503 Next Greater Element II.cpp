/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] Next Greater Element II
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> nge_array(len);
        // unordered_map<int, int> nge_map;
        stack<int> st;

        for (int i = len - 1 + len; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] <= nums[i % len])
            {
                st.pop();
            }
            nge_array[i % len] = st.empty() ? -1 : nums[st.top()];
            // nge_array[i] = st.empty()? -1 : nums2[st.top()];
            st.push(i % len);
        }

        return nge_array;
    }
};
// @lc code=end
