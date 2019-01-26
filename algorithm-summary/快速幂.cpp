
/**
 * Describe：实现快速幂 
 * Author：指点
 * Date：2018/1/24 
 */ 
#include <iostream>
#include <cstdlib>
using namespace std;

// 使用快速幂求出 x^n 的值并返回
double myPow(double x, int n) {
	// 任何不是 0 的数的 0 次幂为 1 
	if (x && n == 0) {
		return 1;
	} else if (x == 0 && n == 0) {
		exit(1);
	}
	// 如果 n 是负数，那么返回结果要进行处理 
	bool nIsNegative = false;
	if (n < 0) {
		nIsNegative = true;
		n = -n;
	}
	
	double res = 1;
	while (n) {
		// 用位运算的方式判断 n 是否为奇数，速度更快，等价于 n%2 
		if (n & 1) {
			res *= x;
		}
		x *= x;
		// 用位运算的方式进行 n/2，速度更快，等价于 n/=2
		n >>= 1;
	}
	// n 是负数？1.0/res 否则 res 
	return nIsNegative ? 1.0/res : res;
} 

int main() {
	double x;
	int n;
	
	while (cin >> x >> n) {
		cout << myPow(x, n) << endl << endl; 
	} 
	
	return 0;
} 
