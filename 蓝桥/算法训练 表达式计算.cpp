
/*
	Create by StarkZhidian on 2018-12-15
	question link: http://lx.lanqiao.cn/problem.page?gpid=T419
	
	表达式计算 
	时间限制：1.0s   内存限制：256.0MB
	提交此题    
	问题描述
	　　输入一个只包含加减乖除和括号的合法表达式，求表达式的值。其中除表示整除。
	输入格式
	　　输入一行，包含一个表达式。
	输出格式
	　　输出这个表达式的值。
	样例输入
	1-2+3*(4-5)
	样例输出
	-4
	数据规模和约定
	　　表达式长度不超过100，表达式运算合法且运算过程都在int内进行。
	
	思路：递归，表达式定义：
	表达式可以是一个项，或者若干个项的 + 和 - 运算得到的值 
	项可以是一个因子，或者若干个因子的 * 和 / 的运算得到的值 
	因子可以是一个整数，也可以是一个表达式。
	目标是求出一个表达式的值，因此可分别为三个定义写三个递归函数：
	表达式->项->因子，通过给出的定义进行顺序调用 
 */
#include <iostream>
#include <cctype>
using namespace std;

int expression(); // 表达式 
int term(); // 项 
int factor(); // 因子 

int expression() {
	// 表达式定义：要么一个项， 
    int res = term();
    char op;
    // 要么若干个项的 + 和 - 运算后的值 
    while (true) {
        op = cin.peek(); // 看一眼输入流的下一个字符，但不取出 
        if (op == '+' || op == '-') {
            cin.get(); // 取出输入流的下一个字符 
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
	// 项定义：要么一个因子， 
	int res = factor();
	char op;
	// 要么若干个因子进行 * 和 / 运算后的值 
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
	// 如果说以 ( 开头，证明括号里面的是另一个表达式 
	if (c == '(') {
		cin.get();
		res = expression();
		cin.get(); // 取出右括号 ) 
	// 否则的话证明是整数（因子的定义：要表达式要么整数），这里是嵌套递归的终止 
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
