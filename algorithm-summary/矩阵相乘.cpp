/**
 * Describe��ʵ�־������
 * Author��ָ��
 * Date��2018/1/24  
 */
#include <iostream>
#include <cstring>
using namespace  std;

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

int main() {
    int m = 2, s = 3, n = 2;
    // ��ʼ�� a ��b ��������
    int **a = new int*[m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[s];
    } 
    int **b = new int*[s];
    for (int i = 0; i < s; i++) {
        b[i] = new int[n];
    }
    cout << "a ����" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < s; j++) {
            a[i][j] = i + j;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "b ����" << endl;
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < n; j++) {
            b[i][j] = i + j;
            cout << b[i][j] << " ";
        }
        cout << endl;
    }

    int **res = matrixMultiply(a, b, 2, 3, 2);
    // �����һ�� 2 �� 2 �е����� 
    cout << "��˵Ľ������" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    // �ͷ�������ڴ�ռ� 
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
