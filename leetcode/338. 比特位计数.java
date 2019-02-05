/**
 * 比特位计数
 * link: https://leetcode-cn.com/problems/counting-bits/
 *
 * 给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。
 *
 * 示例 1:
 *
 * 输入: 2
 * 输出: [0,1,1]
 * 示例 2:
 *
 * 输入: 5
 * 输出: [0,1,1,2,1,2]
 * 进阶:
 *
 * 给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？
 * 要求算法的空间复杂度为O(n)。
 * 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。
 *
 * 思路：假设我们已经知道 x 的二进制中 1 的个数，那么再假设 y 的二进制中 1 的个数比 x 的二进制中 1 的个数多 1  并且 y 是第一个比 x 大并且的整数，
 * 则 res[y] = res[y & (y - 1)] + 1; y & (y - 1) 即为将 y 的二进制中最右边的 1 去后得到的值即为这里的 x，扫描一趟解决问题的关键就在这里
 */
class Solution {
    public int[] countBits(int num) {
        int[] res = new int[num + 1];
        for (int i = 1; i <= num; i++) {
            res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }
}