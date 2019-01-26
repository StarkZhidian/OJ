
/**
 * Describe�����þ����������쳲��������еĵ� n ��ֵ
 * Author��ָ��
 * Date��2018/1/24  
 */
#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

// f(1) �� f(2) ��ֵ 
const ll START[] = {1, 1}; 
// ���� T 
ll **T = NULL;

// ɾ������ռ�ĺ���������������m
void deleteArray(ll **a, int m) {
	if (a != NULL) {
		for (int i = 0; i < m; i++) {
			delete[] a[i];
		} 
		delete[] a;
		a = NULL;
	}
}

// ������� a(m*s ��ģ) �;��� b(s*n ��ģ) ��˵Ľ��������������� 
ll **matrixMultiply(ll **a, ll **b, int m, int s, int n) {
	// ��ʼ�������������� 
	ll **result = new ll*[m];
	for (int i = 0; i < m; i++) {
		result[i] = new ll[n];
		memset(result[i], 0, sizeof(ll)*n);
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
ll **myMatrixPow(ll **a, int m, int n) {
	// ��ʼ���������ľ��� 
	ll **res = new ll*[m];
	for (int i = 0; i < m; i++) {
		res[i] = new ll[m];
		memset(res[i], 0, sizeof(ll)*m);
		// �������ľ����ʼӦ����һ����λ����(����б�Խ���ֵΪ 1������Ϊ 0) 
		res[i][i] = 1;
	} 
	 // ����Ҫɾ��������ռ��ָ�� 
	ll **oldPoint = NULL;
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

// ���쳲��������еĵ� n ���ֵ�������������������������ַ�Χ 
ll getFibo(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	ll res = 0;
	// ��� T ����� n-2 �η�(T^n-2)��ֵ��������������� T ָ����
	T = myMatrixPow(T, 2, n-2); 
	// ������� f(n) ��ֵ, 
	// (res += START[i]*T[i][0] Ϊ f(n-1) ��ֵ��res += START*T[i][1] Ϊ f(n) ��ֵ)
	for (int i = 0; i < 2; i++) {
		res += START[i]*T[i][1];
	}
	return res;
}

int main() {
	// ��ʼ������ T��Ԫ��ֵͨ��������� 
	T = new ll*[2];
	T[0] = new ll[2];
	T[1] = new ll[2];
	
	for (int i = 1; i < 80; i++) {
		/**
		 * ���� T Ԫ��ֵ�� 
		 * 0 1
		 * 1 1
		 */
		T[0][0] = 0;
		T[0][1] = T[1][0] = T[1][1] = 1;
		cout << "��" << i << "��쳲��������е�ֵ��"; 
		cout << getFibo(i) << endl;
	}
	deleteArray(T, 2);
	
	return 0;
}
