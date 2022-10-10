class Solution
{
private:
    void dfs(vector<int> &nums, int begin, vector<vector<int>> &ans)
    {
        if (begin == nums.size())
        {
            ans.emplace_back(nums);
            return;
        }
        for (size_t i = begin; i < nums.size(); i++)
        {
            swap(nums[i], nums[begin]);
            dfs(nums, begin + 1, ans);
            swap(nums[i], nums[begin]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        dfs(nums, 0, ans);
        return ans;
    }
};