/*
 * @lc app=leetcode.cn id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 */

// @lc code=start
class Solution
{
public:
    int result = 0;

    void backtracking(string tiles, vector<bool> &used)
    {
        for (int i = 0; i < tiles.size(); ++i)
        {
            // 这里tiles[i] == tiles[i - 1]代表需要去重的相同数字
            // used[i - 1] == false代表i是i-1的同层节点，因为这个时候i-1并没有被选择，相等于层次去重，这个时候我们去掉的相当于tiles[i]tiles[i-1]，而tiles[i-1]tiles[i]是被我们所接受的，也就是以tiles[i]为根节点的整个树全部去掉
            if (i > 0 && tiles[i] == tiles[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            // 自身去重
            if (used[i] == false)
            {
                used[i] = true;
                result++;
                backtracking(tiles, used);
                used[i] = false;
            }
        }
    }

    int numTilePossibilities(string tiles)
    {
        /*回溯（类似于重复元素子集 + 排列的综合体问题）
            主体思路：我们就按照多叉树的思路来进行分析和剪枝
            1.多叉树结构分析：根节点看作空字符串，多叉树的第i层（从0开始算）代表结果字符串的第i位置可能选择的字符
            2.答案节点：除了根节点的所有子节点都是我们需要的答案（本题的话统计个数即可）
            3.去重：
                思路：对于多叉树的同一层进行分析，如果该层已经选择字符ch作为字符串第i位置的字符，那么就算tiles中ch数量大于1，我们也没必要在本层再次选择ch了
                做法：对于titles字典序升序（降序也可以）排序，目的是让重复元素在titles中的位置是相邻的，然后像重复元素排列问题那样设置一个used数组来记录titles[i]是否被使用过
            4.总结：本题相当于在重复元素排列问题上选取所有子节点
        */
        sort(tiles.begin(), tiles.end());
        vector<bool> used(tiles.size(), false);
        backtracking(tiles, used);
        return result;
    }
};
// @lc code=end
