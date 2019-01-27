/**
 *
    ������ת��������
	
	link: https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1017/
	
	���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

	( ���磬���� [0,1,2,4,5,6,7] ���ܱ�Ϊ [4,5,6,7,0,1,2] )��

	����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻� -1 ��

	����Լ��������в������ظ���Ԫ�ء�

	����㷨ʱ�临�Ӷȱ����� O(log n) ����

	ʾ�� 1:

	����: nums = [4,5,6,7,0,1,2], target = 0
	���: 4
	ʾ�� 2:

	����: nums = [4,5,6,7,0,1,2], target = 3
	���: -1

 */
class Solution {
    public int search(int[] nums, int target) {
        if (nums == null || nums.length == 0) {
            return -1;
        }
        int mid = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1]) {
                mid = i;
                break;
            }
            if (nums[i] == target) {
                return i;
            }
        }
        return Math.max(binarySearch(nums, target, 0, mid), binarySearch(nums, target, mid, nums.length));
    }
    
    int binarySearch(int[] nums, int target, int start, int end) {
        int mid;
        while (start < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return -1;
    }
}