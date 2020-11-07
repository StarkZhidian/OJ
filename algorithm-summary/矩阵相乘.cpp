/**
 * Describe：实现矩阵相乘
 * Author：指点
 * Date：2018/1/24  
 */
#include <iostream>
#include <cstring>
using namespace  std;

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

int main() {
    int m = 2, s = 3, n = 2;
    // 初始化 a 、b 两个矩阵
    int **a = new int*[m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[s];
    } 
    int **b = new int*[s];
    for (int i = 0; i < s; i++) {
        b[i] = new int[n];
    }
    cout << "a 矩阵：" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < s; j++) {
            a[i][j] = i + j;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "b 矩阵：" << endl;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = i + j;
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    int **res = matrixMultiply(a, b, 2, 3, 2);
    // 结果是一个 2 行 2 列的数组 
    cout << "相乘的结果矩阵：" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    // 释放申请的内存空间 
    if (a != NULL) {
        for (int i = 0; i < m; i++) {
            delete[] a[i];
        }
        delete[] a;
        a = NULL;
    }
    if (b != NULL) {
        for (int i = 0; i < s; i++) {
            delete[] b[i];
        }
        delete[] b;
        b = NULL;
    }
    if (res != NULL) {
        for (int i = 0; i < m; i++) {
            delete[] res[i];
        }
        delete[] res;
        res = NULL;
    }
    return 0;
}
