import java.util.HashMap;

/**
 *  最长连续序列: 
 *  link: https://leetcode-cn.com/explore/interview/card/bytedance/243/array-and-sorting/1019/
	给定一个未排序的整数数组，找出最长连续序列的长度。
	
	要求算法的时间复杂度为 O(n)。
	
	示例:
	
	输入: [100, 4, 200, 1, 3, 2]
	输出: 4
	解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
	
	思路：可以用排序（记得去重），也可以用 Map 来记录每一个值所在的连续数字的长度，这里用第二种方法：
	如果某个数已经存在于 HashMap 中，那么不记，否则先遍历其左边的数字，找到连续最左边的数字所在连续数组的长度，加上一，
	之后在遍历其右边的数字，找到连续最右边的数字所在数组的最大长度，加上一，每次进行记录时都更新最大长度，即答案

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