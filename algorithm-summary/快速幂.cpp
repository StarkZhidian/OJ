
/**
 * Describe��ʵ�ֿ����� 
 * Author��ָ��
 * Date��2018/1/24 
 */ 
#include <iostream>
#include <cstdlib>
using namespace std;

// ʹ�ÿ�������� x^n ��ֵ������
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
		n = -n;
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

int main() {
	double x;
	int n;
	
	while (cin >> x >> n) {
		cout << myPow(x, n) << endl << endl; 
	} 
	
	return 0;
} 
