
/**
 * Describe：利用矩阵快速幂求斐波那契数列的第 n 项值
 * Author：指点
 * Date：2018/1/24  
 */
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

// f(1) 和 f(2) 的值 
const ll START[] = {1, 1}; 
// 矩阵 T 
ll **T = NULL;

// 删除数组空间的函数，数组行数：m
void deleteArray(ll **a, int m) {
	if (a != NULL) {
		for (int i = 0; i < m; i++) {
			delete[] a[i];
		} 
		delete[] a;
		a = NULL;
	}
}

// 计算矩阵 a(m*s 规模) 和矩阵 b(s*n 规模) 相乘的结果，并将结果返回 
ll **matrixMultiply(ll **a, ll **b, int m, int s, int n) {
	// 初始化储存结果的数组 
	ll **result = new ll*[m];
	for (int i = 0; i < m; i++) {
		result[i] = new ll[n];
		memset(result[i], 0, sizeof(ll)*n);
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
ll **myMatrixPow(ll **a, int m, int n) {
	// 初始化保存结果的矩阵 
	ll **res = new ll*[m];
	for (int i = 0; i < m; i++) {
		res[i] = new ll[m];
		memset(res[i], 0, sizeof(ll)*m);
		// 保存结果的矩阵初始应该是一个单位矩阵(正向斜对角线值为 1，其余为 0) 
		res[i][i] = 1;
	} 
	 // 保存要删除的数组空间的指针 
	ll **oldPoint = NULL;
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

// 求出斐波那契数列的第 n 项的值，不考虑整数溢出，请控制数字范围 
ll getFibo(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	ll res = 0;
	// 求出 T 矩阵的 n-2 次方(T^n-2)的值，并将结果保存在 T 指针中
	T = myMatrixPow(T, 2, n-2); 
	// 求出最后的 f(n) 的值, 
	// (res += START[i]*T[i][0] 为 f(n-1) 的值，res += START*T[i][1] 为 f(n) 的值)
	for (int i = 0; i < 2; i++) {
		res += START[i]*T[i][1];
	}
	return res;
}

int main() {
	// 初始化矩阵 T，元素值通过计算求得 
	T = new ll*[2];
	T[0] = new ll[2];
	T[1] = new ll[2];
	
	for (int i = 1; i < 80; i++) {
		/**
		 * 矩阵 T 元素值： 
		 * 0 1
		 * 1 1
		 */
		T[0][0] = 0;
		T[0][1] = T[1][0] = T[1][1] = 1;
		cout << "第" << i << "项斐波那契数列的值："; 
		cout << getFibo(i) << endl;
	}
	deleteArray(T, 2);
	
	return 0;
}
