
/**
���죬����ϰ���һ�ҵ������Ӫҵ?customers.length?���ӡ�ÿ���Ӷ���һЩ�˿ͣ�customers[i]���������꣬������Щ�˿Ͷ�������һ���ӽ������뿪��
��ĳЩʱ������ϰ�������� �������ϰ��ڵ� i ������������ô grumpy[i] = 1������ grumpy[i] = 0�� ������ϰ�����ʱ����һ���ӵĹ˿;ͻ᲻���⣬������������������ġ�
����ϰ�֪��һ�����ܼ��ɣ��������Լ����������������Լ�����?X ���Ӳ���������ȴֻ��ʹ��һ�Ρ�
���㷵����һ��Ӫҵ����������ж��ٿͻ��ܹ��е������������

ʾ����

���룺customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], X = 3
�����16
���ͣ�
����ϰ������ 3 ���ӱ����侲��
�е���������ͻ����� = 1 + 1 + 1 + 1 + 7 + 5 = 16.

��ʾ��

1 <= X <=?customers.length ==?grumpy.length <= 20000
0 <=?customers[i] <= 1000
0 <=?grumpy[i] <= 1

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/grumpy-bookstore-owner
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

˼·��������ϰ岻����ʱ�˿͵����������Ѷ�Ӧ�˿�����ֵ��ֵΪ 0����Ϊ�Ѿ�����ˣ���
���������Ǽ����ʣ���������������Ϊ min(X, customers.length) ��Ԫ�غ͵����ֵ
*/
class Solution {
    public int maxSatisfied(int[] customers, int[] grumpy, int X) {
        int res = 0;
		// ������ϰ岻����ʱ�Ĺ˿�����
        for (int i = 0; i < customers.length; i++) {
            if (grumpy[i] == 0) {
                res += customers[i];
				// ��ǰ�±�˿����Ѿ����������ֵΪ 0
                customers[i] = 0;
            }
        }
        int maxCanSaveCount = 0;
        int len = Math.min(X, customers.length);
		// ��� 0~min(x, customers.length) �еĹ˿�����
        for (int i = 0; i < len; i++) {
            maxCanSaveCount += customers[i];
        }
		// ���û�������˼�룬������Ϊ min(x, customers.length) �Ĵ����𲽺��ƣ�������Ԫ�غ͵����ֵ
        int temp = maxCanSaveCount;
        for (int i = X; i < customers.length; i++) {
            temp = temp + customers[i] - customers[i - X];
            maxCanSaveCount = Math.max(maxCanSaveCount, temp);
        }
        return res + maxCanSaveCount;
    }
}