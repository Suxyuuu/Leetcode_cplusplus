// 先转置 再倒序
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 1)
            return;
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};