/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        int n = tokens.size();
        for (int i = 0; i < n; i++)
        {
            string &token = tokens[i];
            if (isNumber(token))
            {
                stk.push(atoi(token.c_str()));
            }
            else
            {
                long num2 = stk.top();
                stk.pop();
                long num1 = stk.top();
                stk.pop();
                switch (token[0])
                {
                case '+':
                    stk.push(num1 + num2);
                    break;
                case '-':
                    stk.push(num1 - num2);
                    break;
                case '*':
                    stk.push(num1 * num2);
                    break;
                case '/':
                    stk.push(num1 / num2);
                    break;
                }
            }
        }
        return stk.top();
    }

    bool isNumber(string &token)
    {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};

// @lc code=end
