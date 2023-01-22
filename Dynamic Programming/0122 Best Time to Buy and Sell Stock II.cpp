/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution
{
public:
    // 可以用dp但属实没必要
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0 || n == 1)
            return 0;

        int buy_price = prices[0];
        // int sold_price = 0;
        int profit = 0;
        int i = 1;
        while (i < n)
        {
            if (prices[i] < buy_price)
            {
                buy_price = prices[i];
            }
            else if (prices[i] > buy_price)
            {
                while (i < n && prices[i] > prices[i - 1])
                {
                    i++;
                }
                // sold_price = prices[i-1];
                profit += prices[i - 1] - buy_price;
                buy_price = i == n ? 0 : prices[i];
            }
            else
            {
                i++;
            }
        }
        return profit;
    }
};
// @lc code=end
