
/** 
 * <! spfa �㷨��bellmanFord �㷨�Ķ����Ż�������ʱ�临�Ӷ�Ϊ O(n*m)��
 * n��m Ϊͼ�Ķ������ͱ���������һ��ͼ�����ĳ����������еĴ�������ͼ�Ķ���������
 * ��ô���ͼ�϶����ڸ��� !> 
 * �������ݣ�5 7
             1 2 2
             1 5 10
             2 3 3
             2 5 7
             3 4 4
             4 5 5
             5 3 6 
 */
#include <cstring> 
#include <iostream>
#include <algorithm>
#include <queue> 
#include <stack>
using namespace std;

const int INF = 999999999;
const int MAXN = 5000;
// first �����¼��¼�±����Ķ���ĵ�һ���ߵı��
// next �����¼�±�������ıߵ���һ���ߵı�� 
int first[MAXN], next[MAXN*MAXN];
// ��¼ÿ���ߵ���Ϣ�������ٽ�� + Ȩֵ 
int start[MAXN*MAXN], end[MAXN*MAXN], weight[MAXN*MAXN];
int dis[MAXN]; // ��¼Դ���㵽ͼ��ÿ������ľ��� 
bool mark[MAXN]; // ������飬��Ƕ����Ƿ��Ѿ���������� 
int count_[MAXN]; // ��¼ÿ����������еĴ��������ڼ�⸺�� 
int route[MAXN]; // ��¼ÿ�����㵽Դ�ڵ�����·�������Ľڵ���Ϣ 

bool spfa(int s, int n) {
	fill(dis + 1, dis + n + 1, INF);
	dis[s] = 0;
	queue<int> que;
	que.push(s);
	route[s] = s; 
	mark[s] = true;
	count_[s]++;
	int startNode, edge;
	while (!que.empty()) {
		startNode = que.front();
		// �� startNode ����ĵ�һ���߿�ʼ�������������� 
		edge = first[startNode];
		// ���ж���Ԫ�س����У��ͷű��
		que.pop();
		mark[start[edge]] = false;
		// ö�ٸö�������г��ߣ����ȣ� 
		while (edge != -1) {
			if (dis[end[edge]] > dis[start[edge]] + weight[edge]) {
				dis[end[edge]] = dis[start[edge]] + weight[edge];
				route[end[edge]] = start[edge]; // ����·���ڵ���Ϣ 
				// ������ɣ������µĶ��������� 
				if (!mark[end[edge]]) {
					que.push(end[edge]);
					mark[end[edge]] = true;
					count_[end[edge]]++;
					// ���ĳ����������д�������ͼ�Ķ���������
					// ��ô���ͼ�϶����ڸ�����
					// ע������ͼ�Ķ�����Ϊ 1~n������� count_[end[edge]] >= n  
					if (count_[end[edge]] >= n) {
						return false;
					}
				} 
			} 
			edge = next[edge]; 
		}
	}
	return true;
}

int main() {
	memset(first, -1, sizeof(int)*MAXN);
	int n, m, s = 1; // ͼ�Ķ����������������·����Դ�ڵ��� 
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> start[i] >> end[i] >> weight[i];
		next[i] = first[start[i]];
		first[start[i]] = i;
	}
	if (!spfa(1, n)) {
		cout << "��ͼ���ڸ�����" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
	}
	
	cout << endl;
	int currentNode;
	for (int i = 1; i <= n; i++) {
		cout << "Դ�ڵ㵽���� " << i << " ��·����Ϣ�� ";
		// ��Ϊ���·������˳��������ģ���ô��Ҫ��ջ����˳��������� 
		stack<int> stk;
		stk.push(i);
		currentNode = route[i];
		while (currentNode != s) {
			stk.push(currentNode);
			currentNode = route[currentNode];
		}
		stk.push(s);
		// ˳���ջ�����·����Ϣ�� 
		int t = -1;
		while (!stk.empty()) {
			if (t != -1) {
				cout << "-->";
			}
			t = stk.top();
			stk.pop();
			cout << t;
		}
		cout <<"     ���룺" << dis[i] << endl;
	}
	
	return 0;
}
