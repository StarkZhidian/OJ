import java.util.HashMap;

/**
 *  ���������: 
 *  link: https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1019/
	����һ��δ������������飬�ҳ���������еĳ��ȡ�
	
	Ҫ���㷨��ʱ�临�Ӷ�Ϊ O(n)��
	
	ʾ��:
	
	����: [100, 4, 200, 1, 3, 2]
	���: 4
	����: ����������� [1, 2, 3, 4]�����ĳ���Ϊ 4��
	
	˼·�����������򣨼ǵ�ȥ�أ���Ҳ������ Map ����¼ÿһ��ֵ���ڵ��������ֵĳ��ȣ������õڶ��ַ�����
	���ĳ�����Ѿ������� HashMap �У���ô���ǣ������ȱ�������ߵ����֣��ҵ���������ߵ�����������������ĳ��ȣ�����һ��
	֮���ڱ������ұߵ����֣��ҵ��������ұߵ����������������󳤶ȣ�����һ��ÿ�ν��м�¼ʱ��������󳤶ȣ�����

 * 
 */
class Solution {
	
    public int longestConsecutive(int[] nums) {
        if (nums == null || nums.length <= 1) {
            return nums != null ? nums.length : 0;
        }
        HashMap<Integer, Integer> map = new HashMap<>(nums.length);
        int res = 0;
        int v;
        for (int i : nums) {
            if (!map.containsKey(i)) {
        		int j = i - 1;
                v = 0;
        		while (map.containsKey(j)) {
        			j--;
                    v++;
        		}
        		if (j == i - 1) {
        			map.put(i, 1);
        			res = Math.max(1, res);
        		} else {
        			map.put(i, v + 1);
        			res = Math.max(res, v + 1);
        		}
        		j = i + 1;
                v = 0;
        		while (map.containsKey(j)) {
        			j++;
                    v++;
        		}
        		if (j > i + 1) {
        			v += map.get(i);
        			map.put(j - 1, v);
        			res = Math.max(v, res);
        		}
            }
        }
        return res;
    }
}