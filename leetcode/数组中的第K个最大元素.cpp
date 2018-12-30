/**
 * Create by StarkZhidian on 2018-12-30
 *
 * leetcode 数组中的第 k 个最大元素
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 *  
 *  在未排序的数组中找到第 k 个最大的元素。请注意，
 	你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

	示例 1:
	
	输入: [3,2,1,5,6,4] 和 k = 2
	输出: 5
	示例 2:
	
	输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
	输出: 4
	
	思路：采用快速排序的分治思想 
 */
class Solution {
public:
    int solve(vector<int> &nums, int k, int start, int end) {
        if (start >= end) {
            return -1;
        }
        int left = start, right = end - 1;
        int t = nums[left];
        while (left < right) {
            while (left < right && nums[right] >= t) {
                right--;
            }
            nums[left] = nums[right];
            while (left < right && nums[left] <= t) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = t;
        // 一轮排序完后，left 左边的数都不大于 nums[left], left 右边的数都不小于 nums[left] 
        if (end - left == k) {
            return nums[left];
        } else if (end - left < k) {
            return solve(nums, k - end + left, start, left);
        } else {
            return solve(nums, k, left + 1, end);
        }
    }

    int findKthLargest(vector<int> &nums, int k) {
        return solve(nums, k, 0, nums.size());
    }
};

