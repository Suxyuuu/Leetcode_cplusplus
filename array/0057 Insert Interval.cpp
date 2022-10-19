class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int len=intervals.size();
        if(len==0)
        {
            intervals.emplace_back(newInterval);
            return intervals;
        }
        intervals.emplace_back(newInterval);
        len++;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int start=0;
        int end=0;
        int index=0;
        for(size_t i=0; i<len; i++)
        {
            if(i==0)
            {
                start=intervals[i][0];
                end=intervals[i][1];
                index=i;
            }
            else if(intervals[index][1]>=intervals[i][0])
            {
                if(intervals[i][1]>end)
                {
                    end=intervals[i][1];
                    index=i;
                }
                // end=max(end, intervals[i][1]);
                continue;
            }
            else
            {
                ans.emplace_back((vector<int>){start, end});
                start=intervals[i][0];
                end=intervals[i][1];
                index=i;
            }
        }
        ans.emplace_back((vector<int>){start, end});
        return ans;
    }
};