/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] Shopping Offers
 */

// @lc code=start
class Solution
{
public:
    int amount = 0;
    int ans = INT_MAX;
    vector<int> valid;

    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        for (size_t i = 0; i < needs.size(); i++)
        {
            amount += price[i] * needs[i];
        }
        ans = min(ans, amount);

        valid.resize(special.size(), 0);
        for (size_t i = 0; i < special.size(); i++)
        {
            if (isValid(price, needs, special, i))
            {
                valid[i] = 1;
            }
        }
        amount = 0;
        dfs(price, special, needs, valid);
        return ans;
    }

    void dfs(vector<int> &price, vector<vector<int>> &special, vector<int> &needs, vector<int> &valid)
    {
        if (isZero(needs))
        {
            ans = min(ans, amount);
            return;
        }
        for (int i = 0; i < special.size(); i++)
        {
            if (valid[i] == 0)
            {
                continue;
            }
        
            int flag = 1;
            for (int j = 0; j < needs.size(); j++)
            {
                if (special[i][j] > needs[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1)
            {
                choose(i, special, needs);
                dfs(price, special, needs, valid);
                unchoose(i, special, needs);
            }
            else
            {
                int before = amount;
                for (size_t i = 0; i < needs.size(); i++)
                {
                    amount += price[i] * needs[i];
                }
                ans = min(ans, amount);
                amount = before;
            }
        }
    }

    void choose(int index, vector<vector<int>> &special, vector<int> &needs)
    {
        for (size_t i = 0; i < needs.size(); i++)
        {
            needs[i] -= special[index][i];
        }
        amount += special[index][needs.size()];
    }

    void unchoose(int index, vector<vector<int>> &special, vector<int> &needs)
    {
        for (size_t i = 0; i < needs.size(); i++)
        {
            needs[i] += special[index][i];
        }
        amount -= special[index][needs.size()];
    }

    bool isZero(const vector<int> &needs)
    {
        for (size_t i = 0; i < needs.size(); i++)
        {
            if (needs[i] != 0)
            {
                return false;
            }
        }
        return true;
    }

    bool isValid(const vector<int> &price, const vector<int> &needs, const vector<vector<int>> &special, int index)
    {
        int s = special[index][needs.size()];
        int p = 0;
        for (int i = 0; i < needs.size(); i++)
        {
            p += price[i] * special[index][i];
        }
        return s < p;
    }
};
// @lc code=end
