/**
 link: https://leetcode-cn.com/problems/koko-eating-bananas/
 题目描述
	
	珂珂喜欢吃香蕉。这里有 N 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 H 小时后回来。
	
	珂珂可以决定她吃香蕉的速度 K （单位：根/小时）。每个小时，她将会选择一堆香蕉，
		从中吃掉 K 根。如果这堆香蕉少于 K 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
	
	珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
	
	返回她可以在 H 小时内吃掉所有香蕉的最小速度 K（K 为整数）。
	
	 
	
	示例 1：
	
	输入: piles = [3,6,7,11], H = 8
	输出: 4
	示例 2：
	
	输入: piles = [30,11,23,4,20], H = 5
	输出: 30
	示例 3：
	
	输入: piles = [30,11,23,4,20], H = 6
	输出: 23
	 
	
	提示：
	
	1 <= piles.length <= 10^4
	piles.length <= H <= 10^9
	1 <= piles[i] <= 10^9
	
	思路：二分法试触 
 */ 
class Solution {
public:
	// 以每小时 k 根速度求出吃完所有香蕉所需时间 
    int host(vector<int>& piles, int k) {
        int size = piles.size(), res = 0;
        for (int i = 0; i < size; i++) {
            res += (piles[i] - 1) / k + 1;
        }
        return res;
    }
    
    int minEatingSpeed(vector<int>& piles, int H) {
        int size = piles.size(), sum = 0, maxCount = 0; 
        for (int i = 0; i < size; i++) {
            maxCount = piles[i] > maxCount ? piles[i] : maxCount;
            sum += piles[i];
        }
        int start = (sum - 1) / H + 1, end = maxCount, mid;
        while (start < end) {
            mid = start + (end - start) / 2;
            // 可以吃完，尝试缩小 mid 的值范围 
            if (H >= host(piles, mid)) {
                end = mid;
            // 每次吃 mid 根，不能在限定时间内吃完，提高 mid 值 
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};
