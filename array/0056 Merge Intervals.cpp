class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int len = intervals.size();
        if (len == 1)
            return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int start = 0;
        int end = 0;
        int index = 0;
        for (size_t i = 0; i < len; i++)
        {
            if (i == 0)
            {
                start = intervals[i][0];
                end = intervals[i][1];
                index = i;
            }
            else if (intervals[index][1] >= intervals[i][0])
            {
                if (intervals[i][1] > end)
                {
                    end = intervals[i][1];
                    index = i;
                }
                // end=max(end, intervals[i][1]);
                continue;
            }
            else
            {
                ans.emplace_back((vector<int>){start, end});
                start = intervals[i][0];
                end = intervals[i][1];
                index = i;
            }
        }
        ans.emplace_back((vector<int>){start, end});
        return ans;
    }
};