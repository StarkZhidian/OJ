
/**
 * 137. 只出现一次的数字 II
 * link: https://leetcode-cn.com/problems/single-number-ii/
 *
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
 *
 * 说明：
 *
 * 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
 *
 * 示例 1:
 *
 * 输入: [2,2,3,2]
 * 输出: 3
 * 示例 2:
 *
 * 输入: [0,1,0,1,0,1,99]
 * 输出: 99
 *
 * 思路：位运算，每一个 int 类型整形数字都是 32 位 01 组成的，用一个容量为 32 的数组记录每一位为 1 的个数，
 * 如果某个下标的 1 的个数不能被 3 整除，证明那个出现过一次的数字这一位是 1 ，循环判断 32 位即可得到结果
 */
class Solution {

    // 统计 t 数字二进制中为 1 的下标，并统计到 two 数组中
    void divide(int t, int[] two) {
        for (int i = 0; i < 32; i++) {
            two[i] += ((t >> i) & 1);
        }
    }
    
    public int singleNumber(int[] nums) {
        int[] ten = new int[32];
        for (int t : nums) {
            divide(t, ten);
        }
        int t = 1;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += (ten[i] % 3) * t;
            t <<= 1;
        }
        return res;
    }
}