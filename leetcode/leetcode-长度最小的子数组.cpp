
/**
 * Create by StarkZhidian on 2019-1-29
    ������С��������
    linK: https://leetcode-cn.com/explore/featured/card/all-about-array/233/sliding-window/971/
    
	����һ������ n ���������������һ�������� s ���ҳ���������������� �� s �ĳ�����С�����������顣��������ڷ������������������飬���� 0��
	
	ʾ��: 
	
	����: s = 7, nums = [2,3,1,2,4,3]
	���: 2
	����: ������ [4,3] �Ǹ������µĳ�����С�����������顣
	
	˼·������˫ָ�� i, j ����һ���������ڣ������ǰ���������е����ĺ� >= s��
	����� res ���ҳ��� i++ ����С�������ڵĳߴ磬���� j++ �����󻬶����ڵĳߴ��Դﵽ�����е����ֺ� >= s ��Ŀ�� 
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
