
/**
今天，书店老板有一家店打算试营业?customers.length?分钟。每分钟都有一些顾客（customers[i]）会进入书店，所有这些顾客都会在那一分钟结束后离开。
在某些时候，书店老板会生气。 如果书店老板在第 i 分钟生气，那么 grumpy[i] = 1，否则 grumpy[i] = 0。 当书店老板生气时，那一分钟的顾客就会不满意，不生气则他们是满意的。
书店老板知道一个秘密技巧，能抑制自己的情绪，可以让自己连续?X 分钟不生气，但却只能使用一次。
请你返回这一天营业下来，最多有多少客户能够感到满意的数量。

示例：

输入：customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
输出：16
解释：
书店老板在最后 3 分钟保持冷静。
感到满意的最大客户数量 = 1 + 1 + 1 + 1 + 7 + 5 = 16.

提示：

1 <= X <=?customers.length ==?grumpy.length <= 20000
0 <=?customers[i] <= 1000
0 <=?grumpy[i] <= 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/grumpy-bookstore-owner
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

思路：先算出老板不生气时顾客的总量，并把对应顾客量的值赋值为 0（因为已经算过了）。
接下来就是计算出剩余的数组连续个数为 min(X, customers.length) 的元素和的最大值
*/
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int res = 0;
		// 先算出老板不生气时的顾客总数
        for (int i = 0; i < customers.length; i++) {
            if (grumpy[i] == 0) {
                res += customers[i];
				// 当前下标顾客数已经计算过，赋值为 0
                customers[i] = 0;
            }
        }
        int maxCanSaveCount = 0;
        int len = Math.min(X, customers.length);
		// 算出 0~min(x, customers.length) 中的顾客总量
        for (int i = 0; i < len; i++) {
            maxCanSaveCount += customers[i];
        }
		// 采用滑动窗口思想，将容量为 min(x, customers.length) 的窗口逐步后移，并更新元素和的最大值
        int temp = maxCanSaveCount;
        for (int i = X; i < customers.length; i++) {
            temp = temp + customers[i] - customers[i - X];
            maxCanSaveCount = Math.max(maxCanSaveCount, temp);
        }
        return res + maxCanSaveCount;
    }
}