
/**
 * Create by StarkZhidian on 2019-1-29
	 1050 �������� ��25 �֣�
	 linK: https://pintia.cn/problem-sets/994805260223102976/problems/994805275146436608?tdsourcetag=s_pctim_aiomsg
	 
	����Ҫ�󽫸����� N �����������ǵ�����˳�����롰�������󡱡���ν���������󡱣���ָ�����Ͻǵ� 1 �����ӿ�ʼ����˳ʱ������������䡣Ҫ�����Ĺ�ģΪ m �� n �У�����������m��n ���� N��m��n���� m?n ȡ���п���ֵ�е���Сֵ��
	
	�����ʽ��
	�����ڵ� 1 ���и���һ�������� N���� 2 �и��� N �����������������������ֲ����� 10
	?4
	?? �����������Կո�ָ���
	
	�����ʽ��
	�����������ÿ�� n �����֣��� m �С����������� 1 ���ո�ָ�����ĩ�����ж���ո�
	
	����������
	12
	37 76 20 98 76 42 53 95 60 81 58 93
	���������
	98 95 93
	42 37 81
	53 20 76
	58 60 76
	
	˼·�����ÿ������������е���������֮����ݹ��ɹ������������ע�⵱ N Ϊ����ʱ����ֱ��һ��һ����������������һ�����Ե㳬ʱ 
 */
#include <stdio.h>
#include <math.h>

#define MAXN 10010
int num[MAXN];
int matrix[MAXN][MAXN];
int N;

// �Ӵ�С���п������� 
void quick_sort(int start, int end) {
	if (start >= end) {
		return ;
	}
	int left = start, right = end;
	int t = num[left];
	while (left < right) {
		while (left < right && t >= num[right]) {
			right--;
		}
		num[left] = num[right];
		while (left < right && t <= num[left]) {
			left++;
		}
		num[right] = num[left];
	}
	num[left] = t;
	quick_sort(start, left - 1);
	quick_sort(left + 1, end);
}

void display(int m, int n) {
	int count = 0;
	int left = 0, top = 0, right = n - 1, bottom = m - 1;
	int i, j;
	// N Ϊ������ֻ��һ�� 
	if (n == 1) {
		for (i = 0; i < N; i++) {
			if (i) {
				printf("\n");
			}
			printf("%d", num[i]);
		} 
	} else { 
		while (count < N) {
			for (i = left; i <= right && count < N; i++) {
				matrix[top][i] = num[count++];
			}
			top++;
			for (i = top; i <= bottom && count < N; i++) {
				matrix[i][right] = num[count++];
			}
			right--;
			for (i = right; i >= left && count < N; i--) {
				matrix[bottom][i] = num[count++];
			}
			bottom--;
			for (i = bottom; i >= top && count < N; i--) {
				matrix[i][left] = num[count++];
			}
			left++;
		}
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (j) {
					printf(" ");
				}
				printf("%d", matrix[i][j]);
			}
			printf("\n");
		}
	} 
}

int main() {
	scanf("%d", &N);
	int i; 
	for (i = 0; i < N; i++) {
		scanf("%d", num + i);
	}
	int m, n;
	n = (int) sqrt(N);
	while (N % n) {
		n--;
	}
	m = N / n;
	quick_sort(0, N - 1);
	display(m, n);
	
	return 0;
}

