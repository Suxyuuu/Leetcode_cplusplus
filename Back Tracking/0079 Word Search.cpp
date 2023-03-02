/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.empty() || word.empty())
        {
            return false;
        }
        int row = board.size(), col = board[0].size();
        vector<vector<int>> f(row, vector<int>(col, 0));
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                if (dfs(board, word, 0, i, j, f))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> &board, string &word,
             int size, int x, int y, vector<vector<int>> &f)
    {
        if (size == word.size())
        {
            return true;
        }
        // outofbound
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[size])
        {
            return false;
        }
        if (f[x][y] == 0)
        {
            f[x][y] = 1;
            if (dfs(board, word, size + 1, x + 1, y, f) || dfs(board, word, size + 1, x - 1, y, f) || dfs(board, word, size + 1, x, y + 1, f) || dfs(board, word, size + 1, x, y - 1, f))
            {
                return true;
            }
            f[x][y] = 0;
        }
        return false;
    }
};
// @lc code=end
