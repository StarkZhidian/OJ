/**
 * Create by StarkZhidian on 2018-12-30
 *
 * leetcode �����еĵ� k �����Ԫ��
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 *  
 *  ��δ������������ҵ��� k ������Ԫ�ء���ע�⣬
 	����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�

	ʾ�� 1:
	
	����: [3,2,1,5,6,4] �� k = 2
	���: 5
	ʾ�� 2:
	
	����: [3,2,3,1,2,4,5,5,6] �� k = 4
	���: 4
	
	˼·�����ÿ�������ķ���˼�� 
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
        // һ���������left ��ߵ����������� nums[left], left �ұߵ�������С�� nums[left] 
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

