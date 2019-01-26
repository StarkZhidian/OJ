#include <stdio.h>
#include <stdlib.h>

static double ACCEPT_WRONG_BOUND = 1e-6; // 可接受的误差最大值 

// 获取 x 的绝对值
double get_abs(double x) { 
	return x < 0 ? -x : x; 
}

// 求出 x 的平方根，如果参数 x 小于 0，那么结束程序 
double get_sqrt(double x) {
	// 负数没有平方根 
	if (x < 0) { 
		fprintf(stderr, "argument x can not be negative!");
		exit(1);
	}
	double start = 0, end = x, mid, cur_res;
	while (1) {
		mid = start + (end - start) / 2;
		cur_res = mid * mid;
		// 如果当前得到的结果和原数之间的误差小于可接受误差最大值，则结束循环 
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
