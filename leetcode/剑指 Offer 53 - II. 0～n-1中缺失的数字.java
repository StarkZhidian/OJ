//一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出
//这个数字。
//
//
//
// 示例 1:
//
// 输入: [0,1,3]
//输出: 2
//
//
// 示例 2:
//
// 输入: [0,1,2,3,4,5,6,7,9]
//输出: 8
//
//
//
// 限制：
//
// 1 <= 数组长度 <= 10000
// Related Topics 数组 二分查找
// 👍 75 👎 0

/**
 * 思路：
 * 二分查找，每次得到中间的数字（middle）的时候，
 * 需要将 middle 和其左边相邻的一个数字/右边相邻的一个数字进行判断，得到缺失的数字是否找到，
 * 如果没找到，则根据条件缩小区间范围
 */


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public int missingNumber(int[] nums) {
        if (nums == null || nums.length <= 0) {
            return -1;
        }
        int startIndex = 0;
        int endIndex = nums.length - 1;
        int midIndex;
        while (startIndex <= endIndex) {
            midIndex = startIndex + ((endIndex - startIndex) >>> 1);
            if (midIndex > 0 && nums[midIndex] - nums[midIndex - 1] > 1) {
                return nums[midIndex] - 1;
            } else if (midIndex < endIndex && nums[midIndex + 1] - nums[midIndex] > 1) {
                return nums[midIndex + 1] - 1;
            } else if (nums[midIndex] - nums[startIndex] == midIndex - startIndex) {
                startIndex = midIndex + 1;
            } else if (nums[endIndex] - nums[midIndex] == endIndex - midIndex) {
                endIndex = midIndex - 1;
            }
        }
        // 如果在二分查找中没有找到缺失的数字，则说明缺失的数字在最左边或者最右边，
        // 此时根据最左边的数字是否为 0 来判断缺失的数字的方位
        return nums[0] == 0 ? nums[nums.length - 1] + 1 : 0;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
