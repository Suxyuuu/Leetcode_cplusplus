class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool flag[10] = {};
        int k = 0;

        for (size_t i = 0; i < 9; i++)
        {
            for (size_t x = 0; x < 10; x++)
            {
                flag[x] = false;
            }

            for (size_t j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    k = board[i][j] - '0';
                    if (flag[k] == true)
                    {
                        return false;
                    }
                    else
                    {
                        flag[k] = true;
                    }
                }
            }
        }

        for (size_t i = 0; i < 9; i++)
        {
            for (size_t x = 0; x < 10; x++)
            {
                flag[x] = false;
            }

            for (size_t j = 0; j < 9; j++)
            {
                if (board[j][i] != '.')
                {
                    k = board[j][i] - '0';
                    if (flag[k] == true)
                    {
                        return false;
                    }
                    else
                    {
                        flag[k] = true;
                    }
                }
            }
        }

        for (size_t i = 0; i < 9; i += 3)
        {
            for (size_t j = 0; j < 9; j += 3)
            {
                for (size_t x = 0; x < 10; x++)
                {
                    flag[x] = false;
                }

                for (size_t m = i; m < i + 3; m++)
                {
                    for (size_t n = j; n < j + 3; n++)
                    {
                        if (board[m][n] != '.')
                        {
                            k = board[m][n] - '0';
                            if (flag[k] == true)
                            {
                                return false;
                            }
                            else
                            {
                                flag[k] = true;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};