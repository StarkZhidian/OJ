
/**
 * Describe：实现矩阵快速幂 
 * Author：指点
 * Date：2018/1/24  
 */
#include <iostream>
#include <cstring>
using namespace  std;

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

// 删除数组空间的函数，数组行数：m
void deleteArray(int **a, int m) {
	if (a != NULL) {
		for (int i = 0; i < m; i++) {
			delete[] a[i];
		} 
		delete[] a;
		a = NULL;
	}
}

// 计算矩阵 a(m*s 规模) 和矩阵 b(s*n 规模) 相乘的结果，并将结果返回 
int **matrixMultiply(int **a, int **b, int m, int s, int n) {
	// 初始化储存结果的数组 
	int **result = new int*[m];
	for (int i = 0; i < m; i++) {
		result[i] = new int[n];
		memset(result[i], 0, sizeof(int)*n);
	}
	// 进行矩阵相乘计算 
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < s; k++) {
				result[i][j] += a[i][k]*b[k][j];
			}
		}
	} 
	return result;
}

// 求出矩阵 a(m*m 规模，只有方阵才可以自我相乘) 的 n 次方，并将结果返回 
int **myMatrixPow(int **a, int m, int n) {
	// 初始化保存结果的矩阵 
	int **res = new int*[m];
	for (int i = 0; i < m; i++) {
		res[i] = new int[m];
		memset(res[i], 0, sizeof(int)*m);
		// 保存结果的矩阵初始应该是一个单位矩阵(正向斜对角线值为 1，其余为 0) 
		res[i][i] = 1;
	} 
	 // 保存要删除的数组空间的指针 
	int **oldPoint = NULL;
	while (n) {
		if (n & 1) {
			// 保存 res 指针当前的内存地址 
			oldPoint = res; 
			// res 指向储存矩阵相乘结果的数组的地址 
			res = matrixMultiply(res, a, m, m, m); 
			// 删除 res 指针原有的内存空间 
			deleteArray(oldPoint, m); 
		}
		// 保存 a 指针当前的内存地址 
		oldPoint = a;
		// a 指向储存矩阵相乘结果的数组的地址  
		a = matrixMultiply(a, a, m, m, m); 
		// 删除 a 指针原有的内存空间 
		deleteArray(oldPoint, m); 
		
		n >>= 1; 
	}
	return res;
} 

int main() {
	int m = 2;
	// 初始化 a 方阵 
	int **a = new int*[m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[m];
	} 
	cout << "a 矩阵：" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = i + j;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	for (int i = 0; i < 10; i++) {
		// 计算结果 
		int **res = myMatrixPow(a, m, i);
		cout << "a 矩阵的 " << i << " 次方计算结果：" << endl;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
		// 释放申请的内存空间 
		deleteArray(res, m);
	}
	deleteArray(a, m);
	
	return 0;
}


