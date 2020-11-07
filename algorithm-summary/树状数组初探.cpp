

/**
 * <!! 树状数组不能对值为 0 的下标进行操作，即当下标 x 值为 0 时， 
 *     x & (-x) 的值为 0 ，会造成死循环 !!> 
 */
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAXN = 100010;
int treeArray[MAXN];

int lowbit(int x) {
	return x & (-x);
}

void plus_(int pos, int value) {
	while (pos < MAXN) {
		treeArray[pos] += value;
		pos += lowbit(pos);
	}
}

// 求前 n 项和 
int getSum(int n) {
	if (n >= MAXN) {
		exit(1);
	}
	int sum = 0;
	while (n > 0) {
		sum += treeArray[n];
		n -= lowbit(n);
	}
	return sum;
}

int main() {
	int n = 16;
	for (int i = 1; i <= n; i++) {
		plus_(i, 10);
		for (int j = 1; j <= n; j++) {
			cout << treeArray[j] << " ";
		} 
		cout << endl;
	}
	for (int i = n; i > 0; i--) {
		cout << getSum(i) << endl; 
	}
	
	return 0;
} 
