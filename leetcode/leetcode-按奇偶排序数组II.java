/**
 *  按奇偶排序数组 II
 *  link: https://leetcode-cn.com/problems/sort-array-by-parity-ii/
 *
 * 给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。
 *
 * 对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。
 *
 * 你可以返回任何满足上述条件的数组作为答案。
 *
 *
 *
 * 示例：
 *
 * 输入：[4,2,5,7]
 * 输出：[4,5,2,7]
 * 解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 *
 *
 * 提示：
 *
 * 2 <= A.length <= 20000
 * A.length % 2 == 0
 * 0 <= A[i] <= 1000
 *
 * 思路：没什么思路，对偶数 / 奇数下标的数字进行判断，如果不合格就交换奇数 / 偶数中的对应合格数字
 */
class Solution {

    boolean isOdd(int n) {
        return (n & 1) == 1;
    }

    void swap(int[] nums, int a, int b) {
        nums[a] ^= nums[b];
        nums[b] ^= nums[a];
        nums[a] ^= nums[b];
    }

    public int[] sortArrayByParityII(int[] A) {
        if (A == null || A.length <= 1) {
            return A;
        }
        int j = 1;
        for (int i = 0; i < A.length - 1; i += 2) {
            if (isOdd(A[i])) {
                while (j < A.length - 1 && isOdd(A[j])) {
                    j += 2;
                }
                swap(A, i, j);
            }
        }
        return A;
    }
}