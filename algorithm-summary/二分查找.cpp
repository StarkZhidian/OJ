
/**
 * 二分查找关于范围选择的两种写法 
 */
#include <iostream>
using namespace std;

// search bound: [start, end]
int binarySearch(int start, int end, int arr[], int goal) {
	if (start > end || arr == NULL) {
		return -1;
	}
	int mid;
	while (start <= end) {
		mid = start + ((end - start) >> 1);
		if (arr[mid] < goal) {
			start = mid + 1;
		} else if (arr[mid] > goal) {
			end = mid - 1;
		} else {
			return mid;
		}
	}
	return -1;
}

// search bound: [start, end)
int binarySearch2(int start, int end, int arr[], int goal) {
	if (start > end || arr == NULL) {
		return -1;
	}
	int mid;
	while (start < end) {
		mid = start + ((end - start) >> 1);
		if (arr[mid] < goal) {
			start = mid + 1;
		} else if (arr[mid] > goal) {
			end = mid;
		} else {
			return mid;
		}
	}
	return -1;
}

int main() {
	int len = 6;
	int arr[] = {1, 2, 3, 4, 5, 6};
	for (int i = 0; i < len; i++) {
		cout << binarySearch(0, len - 1, arr, arr[i]) << ", ";
		cout << binarySearch2(0, len, arr, arr[i]) << endl;
	}
	return 0;
} 
