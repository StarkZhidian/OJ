
/**
 * Create by StarkZhidian on 2019-1-29
    长度最小的子数组
    linK: https://leetcode-cn.com/explore/featured/card/all-about-array/233/sliding-window/971/
    
	给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
	
	示例: 
	
	输入: s = 7, nums = [2,3,1,2,4,3]
	输出: 2
	解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
	
	思路：采用双指针 i, j 构造一个滑动窗口，如果当前滑动窗口中的数的和 >= s，
	则更新 res 并且尝试 i++ 来缩小滑动窗口的尺寸，否则 j++ 来增大滑动窗口的尺寸以达到窗口中的数字和 >= s 的目的 
 */
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) {
            return size == 0 ? 0 : (nums[0] >= s ? 1 : 0);
        }
        int i = 0, j = i;
        int sum = 0, res = size + 1;
        while (j < size) {
            sum += nums[j];
            while (sum >= s) {
                res = min(res, j - i + 1);
                sum -= nums[i++];
            }
            j++;
        }
        return res == size + 1 ? 0 : res;
    }
};
