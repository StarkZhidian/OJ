/**
 link: https://leetcode-cn.com/problems/koko-eating-bananas/
 ��Ŀ����
	
	����ϲ�����㽶�������� N ���㽶���� i ������ piles[i] ���㽶�������Ѿ��뿪�ˣ����� H Сʱ�������
	
	������Ծ��������㽶���ٶ� K ����λ����/Сʱ����ÿ��Сʱ��������ѡ��һ���㽶��
		���гԵ� K �����������㽶���� K ���������Ե���ѵ������㽶��Ȼ����һСʱ�ڲ����ٳԸ�����㽶��  
	
	����ϲ�������ԣ�����Ȼ���ھ�������ǰ�Ե����е��㽶��
	
	������������ H Сʱ�ڳԵ������㽶����С�ٶ� K��K Ϊ��������
	
	 
	
	ʾ�� 1��
	
	����: piles = [3,6,7,11], H = 8
	���: 4
	ʾ�� 2��
	
	����: piles = [30,11,23,4,20], H = 5
	���: 30
	ʾ�� 3��
	
	����: piles = [30,11,23,4,20], H = 6
	���: 23
	 
	
	��ʾ��
	
	1 <= piles.length <= 10^4
	piles.length <= H <= 10^9
	1 <= piles[i] <= 10^9
	
	˼·�����ַ��Դ� 
 */ 
class Solution {
public:
	// ��ÿСʱ k ���ٶ�������������㽶����ʱ�� 
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
            // ���Գ��꣬������С mid ��ֵ��Χ 
            if (H >= host(piles, mid)) {
                end = mid;
            // ÿ�γ� mid �����������޶�ʱ���ڳ��꣬��� mid ֵ 
            } else {
                start = mid + 1;
            }
        }
        return start;
    }
};
