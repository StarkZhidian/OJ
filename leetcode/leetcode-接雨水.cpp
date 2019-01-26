
/*
  ����ˮ
���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��

ͼ����https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/22/rainwatertrap.png 

������������ [0,1,0,2,1,0,1,3,2,1,2,1] ��ʾ�ĸ߶�ͼ������������£����Խ� 6 ����λ����ˮ����ɫ���ֱ�ʾ��ˮ���� ��л Marcos ���״�ͼ��

ʾ��:

����: [0,1,0,2,1,0,1,3,2,1,2,1]
���: 6
 */ 
class Solution {
public:
    int trap(vector<int>& height) {
        int x = height.size();
        if (x < 3) {
        	return 0;
		}
		int res = 0;
		int maxx = height[0];
		int maxIndex = 0;
		for (int i = 1; i < x; i++) {
			if (maxx < height[i]) {
				maxx = height[i];
				maxIndex = i;
			} 
		}
		int start = height[0];
		for (int i = 1; i < maxIndex; i++) {
			if (height[i] > start) {
				start = height[i];
			} else {
				res += start - height[i];
			}
		}
		start = height[x - 1];
		for (int i = x - 2; i > maxIndex; i--) {
			if (height[i] > start) {
				start = height[i];
			} else {
				res += start - height[i];
			}
		}
        return res;
    }
};
