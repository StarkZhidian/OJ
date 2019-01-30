
/**
 * Create by StarkZhidian on 2019-1-29
	 1050 螺旋矩阵 （25 分）
	 linK: https://pintia.cn/problem-sets/994805260223102976/problems/994805275146436608?tdsourcetag=s_pctim_aiomsg
	 
	本题要求将给定的 N 个正整数按非递增的顺序，填入“螺旋矩阵”。所谓“螺旋矩阵”，是指从左上角第 1 个格子开始，按顺时针螺旋方向填充。要求矩阵的规模为 m 行 n 列，满足条件：m×n 等于 N；m≥n；且 m?n 取所有可能值中的最小值。
	
	输入格式：
	输入在第 1 行中给出一个正整数 N，第 2 行给出 N 个待填充的正整数。所有数字不超过 10
	?4
	?? ，相邻数字以空格分隔。
	
	输出格式：
	输出螺旋矩阵。每行 n 个数字，共 m 行。相邻数字以 1 个空格分隔，行末不得有多余空格。
	
	输入样例：
	12
	37 76 20 98 76 42 53 95 60 81 58 93
	输出样例：
	98 95 93
	42 37 81
	53 20 76
	58 60 76
	
	思路：采用快速排序将数组中的数字排序，之后根据规律构造出螺旋矩阵，注意当 N 为素数时可以直接一行一个数输出，否则最后一个测试点超时 
 */
#include <stdio.h>
#include <math.h>

#define MAXN 10010
int num[MAXN];
int matrix[MAXN][MAXN];
int N;

// 从大到小进行快速排序 
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
	// N 为素数，只有一列 
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

