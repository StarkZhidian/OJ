
/**
 * Describe��ʵ�־�������� 
 * Author��ָ��
 * Date��2018/1/24  
 */
#include <iostream>
#include <cstring>
using namespace  std;

double myPow(double x, int n) {
	// �κβ��� 0 ������ 0 ����Ϊ 1 
	if (x && n == 0) {
		return 1;
	} else if (x == 0 && n == 0) {
		exit(1);
	}
	// ��� n �Ǹ�������ô���ؽ��Ҫ���д��� 
	bool nIsNegative = false;
	if (n < 0) {
		nIsNegative = true;
	}
	
	double res = 1;
	while (n) {
		// ��λ����ķ�ʽ�ж� n �Ƿ�Ϊ�������ٶȸ��죬�ȼ��� n%2 
		if (n & 1) {
			res *= x;
		}
		x *= x;
		// ��λ����ķ�ʽ���� n/2���ٶȸ��죬�ȼ��� n/=2
		n >>= 1;
	}
	// n �Ǹ�����1.0/res ���� res 
	return nIsNegative ? 1.0/res : res;
} 

// ɾ������ռ�ĺ���������������m
void deleteArray(int **a, int m) {
	if (a != NULL) {
		for (int i = 0; i < m; i++) {
			delete[] a[i];
		} 
		delete[] a;
		a = NULL;
	}
}

// ������� a(m*s ��ģ) �;��� b(s*n ��ģ) ��˵Ľ��������������� 
int **matrixMultiply(int **a, int **b, int m, int s, int n) {
	// ��ʼ�������������� 
	int **result = new int*[m];
	for (int i = 0; i < m; i++) {
		result[i] = new int[n];
		memset(result[i], 0, sizeof(int)*n);
	}
	// ���о�����˼��� 
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < s; k++) {
				result[i][j] += a[i][k]*b[k][j];
			}
		}
	} 
	return result;
}

// ������� a(m*m ��ģ��ֻ�з���ſ����������) �� n �η�������������� 
int **myMatrixPow(int **a, int m, int n) {
	// ��ʼ���������ľ��� 
	int **res = new int*[m];
	for (int i = 0; i < m; i++) {
		res[i] = new int[m];
		memset(res[i], 0, sizeof(int)*m);
		// �������ľ����ʼӦ����һ����λ����(����б�Խ���ֵΪ 1������Ϊ 0) 
		res[i][i] = 1;
	} 
	 // ����Ҫɾ��������ռ��ָ�� 
	int **oldPoint = NULL;
	while (n) {
		if (n & 1) {
			// ���� res ָ�뵱ǰ���ڴ��ַ 
			oldPoint = res; 
			// res ָ�򴢴������˽��������ĵ�ַ 
			res = matrixMultiply(res, a, m, m, m); 
			// ɾ�� res ָ��ԭ�е��ڴ�ռ� 
			deleteArray(oldPoint, m); 
		}
		// ���� a ָ�뵱ǰ���ڴ��ַ 
		oldPoint = a;
		// a ָ�򴢴������˽��������ĵ�ַ  
		a = matrixMultiply(a, a, m, m, m); 
		// ɾ�� a ָ��ԭ�е��ڴ�ռ� 
		deleteArray(oldPoint, m); 
		
		n >>= 1; 
	}
	return res;
} 

int main() {
	int m = 2;
	// ��ʼ�� a ���� 
	int **a = new int*[m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[m];
	} 
	cout << "a ����" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = i + j;
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	for (int i = 0; i < 10; i++) {
		// ������ 
		int **res = myMatrixPow(a, m, i);
		cout << "a ����� " << i << " �η���������" << endl;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
		// �ͷ�������ڴ�ռ� 
		deleteArray(res, m);
	}
	deleteArray(a, m);
	
	return 0;
}


