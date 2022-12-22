/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] Asteroid Collision
 */

// @lc code=start
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int len = asteroids.size();
        if (len == 0)
            return {};
        vector<int> result;

        for (int i = 0; i < len; i++)
        {
            if (asteroids[i] >= 0)
            {
                result.emplace_back(asteroids[i]);
            }
            else
            {
                if (result.empty())
                {
                    result.emplace_back(asteroids[i]);
                    continue;
                }
                bool isZero = false;
                while (!result.empty())
                {
                    int temp = result.back();
                    if (temp < 0)
                    {
                        result.emplace_back(asteroids[i]);
                        break;
                    }
                    else
                    {
                        if ((temp + asteroids[i]) < 0)
                        {
                            result.pop_back();
                        }
                        else if ((temp + asteroids[i]) == 0)
                        {
                            result.pop_back();
                            isZero = true;
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
                if (result.empty() && !isZero)
                {
                    result.emplace_back(asteroids[i]);
                }
            }
        }
        return result;
    }
};
// @lc code=end
