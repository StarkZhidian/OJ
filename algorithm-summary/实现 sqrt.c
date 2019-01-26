#include <stdio.h>
#include <stdlib.h>

static double ACCEPT_WRONG_BOUND = 1e-6; // �ɽ��ܵ�������ֵ 

// ��ȡ x �ľ���ֵ
double get_abs(double x) { 
	return x < 0 ? -x : x; 
}

// ��� x ��ƽ������������� x С�� 0����ô�������� 
double get_sqrt(double x) {
	// ����û��ƽ���� 
	if (x < 0) { 
		fprintf(stderr, "argument x can not be negative!");
		exit(1);
	}
	double start = 0, end = x, mid, cur_res;
	while (1) {
		mid = start + (end - start) / 2;
		cur_res = mid * mid;
		// �����ǰ�õ��Ľ����ԭ��֮������С�ڿɽ���������ֵ�������ѭ�� 
		if (get_abs(cur_res - x) <= ACCEPT_WRONG_BOUND) {
			break;
		} 
		if (cur_res > x) {
			end = mid;
		} else {
			start = mid;
		}
	}
	return mid;
}

int main() {
	double x;
	do {
		scanf("%lf", &x);
		printf("%lf\n", get_sqrt(x));
	} while (x >= 0);
	
	return 0;
}
