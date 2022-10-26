/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Automaton
{
    string state = "start";
    unordered_map<string, vector<string>> table = {
        // state : is_space, is_+/-, is_digit, other
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}};

    int get_col(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;
    bool flag_out = false;

    void get(char c)
    {
        state = table[state][get_col(c)];
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            if (sign == 1 && ans >= (long long)INT_MAX)
            {
                ans = (long long)INT_MAX;
                flag_out = true;
            }
            else if (sign == -1 && ans >= -(long long)INT_MIN)
            {
                ans = -(long long)INT_MIN;
                flag_out = true;
            }
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
        else if (state == "end")
        {
            flag_out = true;
        }
    }
};

class Solution
{
public:
    int myAtoi(string str)
    {
        Automaton automaton;
        for (char c : str)
        {
            if (automaton.flag_out)
            {
                break;
            }
            automaton.get(c);
        }
        return automaton.sign * automaton.ans;
    }
};

// @lc code=end
