//数组中占比超过一半的元素称之为主要元素。给定一个整数数组，找到它的主要元素。若没有，返回-1。
//
// 示例 1：
//
// 输入：[1,2,5,9,5,9,5,5,5]
//输出：5
//
//
//
// 示例 2：
//
// 输入：[3,2]
//输出：-1
//
//
//
// 示例 3：
//
// 输入：[2,2,1,1,1,2,2]
//输出：2
//
//
//
// 说明：
//你有办法在时间复杂度为 O(N)，空间复杂度为 O(1) 内完成吗？
// Related Topics 位运算 数组 分治算法
// 👍 43 👎 0

/**
 * 思路：最容易想到的办法：使用 Map，key 为出现的数字，value 为对应数字出现的次数，
 * 遍历 nums，每次向 map 中 put 数据的时候和当前出现次数最多的数字对比，更新数字值
 * 最后，如果统计到的数字出现次数大于 nums.length / 2，则有解，否则返回 -1，
 * 时间复杂度 O(N)，空间复杂度 O(N)，代码如下：
 * class Solution {
 *     public int majorityElement(int[] nums) {
 *         if (nums == null || nums.length < 1) {
 *             return -1;
 *         }
 *         Map<Integer, Integer> numberCounts = new HashMap<>();
 *         int currentCount;
 *         int maxNumber = -1;
 *         int maxCount = Integer.MIN_VALUE;
 *         for (int num: nums) {
 *             currentCount = 1;
 *             if (numberCounts.containsKey(num)) {
 *                 currentCount += numberCounts.get(num);
 *             }
 *             numberCounts.put(num, currentCount);
 *             if (currentCount > maxCount) {
 *                 maxNumber = num;
 *                 maxCount = currentCount;
 *             }
 *         }
 *         return maxCount > (nums.length / 2) ? maxNumber : -1;
 *     }
 * }
 *
 * 进阶：投票算法选出众数，而后验证众数的数量是不是大于 nums.length / 2
 */

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int majorityElement(int[] nums) {
        if (nums == null) {
            return -1;
        }
        int total = 1;
        int resultNumber = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (resultNumber == nums[i]) {
                total++;
            } else {
                total--;
            }
            if (total < 0) {
                resultNumber = nums[i];
                total = 1;
            }
        }
        // 最后验证该数的数目是不是大于 nums.length / 2
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == resultNumber) {
                count++;
            }
        }
        return count > nums.length / 2 ? resultNumber : -1;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
