class Solution
{
public:
    void dfs(vector<int> nums, vector<vector<int>> &ans, vector<int> &path, vector<bool> &used)
    {
        if (path.size() == nums.size())
        {
            ans.emplace_back(path);
            return;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            {
                continue;
            }
            if (!used[i])
            {
                path.emplace_back(nums[i]);
                used[i] = true;
                dfs(nums, ans, path, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int len = nums.size();
        vector<vector<int>> ans;
        if (len == 1)
        {
            ans.emplace_back(nums);
            return ans;
        }
        vector<bool> used(nums.size(), false);
        vector<int> path;
        sort(nums.begin(), nums.end());
        dfs(nums, ans, path, used);
        return ans;
    }
};