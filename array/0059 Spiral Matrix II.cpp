class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {

        int cur = 1;
        int up = 0;
        int down = n - 1;
        int left = 0;
        int right = n - 1;
        vector<vector<int>> ans(n, vector<int>(n, 1));
        while (true)
        {
            for (int i = left; i <= right; i++)
            {
                ans[up][i] = cur++;
            }
            if (++up > down)
                break;
            for (int i = up; i <= down; i++)
            {
                ans[i][right] = cur++;
            }
            if (--right < left)
                break;
            for (int i = right; i >= left; i--)
            {
                ans[down][i] = cur++;
            }
            if (--down < up)
                break;
            for (int i = down; i >= up; i--)
            {
                ans[i][left] = cur++;
            }
            if (++left > right)
                break;
        }
        return ans;
    }
};