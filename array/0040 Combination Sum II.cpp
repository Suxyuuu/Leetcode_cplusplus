class Solution
{
private:
    void dfs(vector<int> &candidates, int begin, int target, vector<int> &path, vector<vector<int>> &res)
    {
        if (target == 0)
        {
            res.emplace_back(path);
            return;
        }
        for (size_t i = begin; i < candidates.size(); i++)
        {
            if (target - candidates[i] < 0)
            {
                break;
            }
            else
            {
                if (i > begin && candidates[i] == candidates[i - 1])
                    continue;
                path.emplace_back(candidates[i]);
                dfs(candidates, i + 1, target - candidates[i], path, res);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, path, res);
        return res;
    }
};