
/**
 * Create by StarkZhidian on 2019-1-25 
 * λͼ��: ���ڴ�������������״̬����״̬���ٵ���� 
 * �Դ������ݲ���Ϊ����
 * �� 40 �ڸ�δ��������Ҫ�����ĳ�����Ƿ������ 40 �ڸ������� 
 */
#include <iostream>
#include <cstdlib> 
using namespace std;

const int MAXN = 0x7fffffff;
const int LEN = MAXN / 32; 
int bit[LEN];

/**
 * ��ĳ��������λͼ������ 
 */
void insertNum(int num) {
	int index = num / 32;
	int mod = num % 32;
	bit[index] |= (1 << (31 - mod));
}

/**
 * ���ĳ�����Ƿ���� 
 */
bool testExists(int num) {
	int index = num / 32;
	int mod = num % 32;
	return ((bit[index] >> (31 - mod)) & 1);
}

int main() {
	int num[] = {1, 4, 5, 10, 15};
	int testNum[] = {1, 4, 6, 9, 15};
	for (int i = 0; i < 5; i++) {
		insertNum(num[i]);
	}
	for (int i = 0; i < 5; i++) {
		cout << testExists(testNum[i]) << " ";
	}
	
	return 0;
}
