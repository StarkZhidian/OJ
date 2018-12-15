
/*
	Create by StarkZhidian on 2018-12-15
	question link: http://lx.lanqiao.cn/problem.page?gpid=T419
	
	���ʽ���� 
	ʱ�����ƣ�1.0s   �ڴ����ƣ�256.0MB
	�ύ����    
	��������
	��������һ��ֻ�����Ӽ��Գ������ŵĺϷ����ʽ������ʽ��ֵ�����г���ʾ������
	�����ʽ
	��������һ�У�����һ�����ʽ��
	�����ʽ
	�������������ʽ��ֵ��
	��������
	1-2+3*(4-5)
	�������
	-4
	���ݹ�ģ��Լ��
	�������ʽ���Ȳ�����100�����ʽ����Ϸ���������̶���int�ڽ��С�
	
	˼·���ݹ飬���ʽ���壺
	���ʽ������һ����������ɸ���� + �� - ����õ���ֵ 
	�������һ�����ӣ��������ɸ����ӵ� * �� / ������õ���ֵ 
	���ӿ�����һ��������Ҳ������һ�����ʽ��
	Ŀ�������һ�����ʽ��ֵ����˿ɷֱ�Ϊ��������д�����ݹ麯����
	���ʽ->��->���ӣ�ͨ�������Ķ������˳����� 
 */
#include <iostream>
#include <cctype>
using namespace std;

int expression(); // ���ʽ 
int term(); // �� 
int factor(); // ���� 

int expression() {
	// ���ʽ���壺Ҫôһ��� 
    int res = term();
    char op;
    // Ҫô���ɸ���� + �� - ������ֵ 
    while (true) {
        op = cin.peek(); // ��һ������������һ���ַ�������ȡ�� 
        if (op == '+' || op == '-') {
            cin.get(); // ȡ������������һ���ַ� 
            if (op == '+') {
                res += term();
            } else {
            	res -= term(); 
            }
        } else {
        	break;
		}
    }
    return res;
}

int term() {
	// ��壺Ҫôһ�����ӣ� 
	int res = factor();
	char op;
	// Ҫô���ɸ����ӽ��� * �� / ������ֵ 
	while (true) {
		op = cin.peek();
		if (op == '*' || op == '/') {
			cin.get();
			if (op == '*') {
				res *= factor();
			} else {
				res /= factor();
			}
		} else {
			break;
		}
	}
	return res;
}

int factor() {
	int res = 0;
	char c = cin.peek();
	// ���˵�� ( ��ͷ��֤���������������һ�����ʽ 
	if (c == '(') {
		cin.get();
		res = expression();
		cin.get(); // ȡ�������� ) 
	// ����Ļ�֤�������������ӵĶ��壺Ҫ���ʽҪô��������������Ƕ�׵ݹ����ֹ 
	} else {
		while (isdigit(c)) {
			res = res * 10 + c - '0';
			cin.get();
			c = cin.peek();
		}
	}
	return res;
}

int main() {
    cout << expression() << endl;
    return 0;
}
