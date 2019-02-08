
/**
 * Create by StarkZhidian on 2019-1-25 
 * 位图法: 用于处理数据量大并且状态数据状态较少的情况 
 * 以大量数据查找为例：
 * 给 40 亿个未排序数，要求查找某个数是否存在这 40 亿个数里面 
 */
#include <iostream>
#include <cstdlib> 
using namespace std;

const int MAXN = 0x7fffffff;
const int LEN = MAXN / 32; 
int bit[LEN];

/**
 * 将某个数插入位图数组中 
 */
void insertNum(int num) {
	int index = num / 32;
	int mod = num % 32;
	bit[index] |= (1 << (31 - mod));
}

/**
 * 检测某个数是否存在 
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
