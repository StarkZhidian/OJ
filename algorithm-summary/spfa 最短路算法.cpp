
/** 
 * <! spfa 算法，bellmanFord 算法的队列优化，最大的时间复杂度为 O(n*m)，
 * n，m 为图的顶点数和边数，对于一个图，如果某个顶点入队列的次数大于图的顶点总数，
 * 那么这个图肯定存在负环 !> 
 * 测试数据：5 7
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
// first 数组记录记录下标代表的顶点的第一条边的编号
// next 数组记录下标所代表的边的下一条边的编号 
int first[MAXN], next[MAXN*MAXN];
// 记录每条边的信息：两个临界点 + 权值 
int start[MAXN*MAXN], end[MAXN*MAXN], weight[MAXN*MAXN];
int dis[MAXN]; // 记录源顶点到图的每个顶点的距离 
bool mark[MAXN]; // 标记数组，标记顶点是否已经加入队列中 
int count_[MAXN]; // 记录每个顶点入队列的次数，用于检测负环 
int route[MAXN]; // 记录每个顶点到源节点的最短路径经过的节点信息 

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
		// 从 startNode 顶点的第一条边开始，缩放其他顶点 
		edge = first[startNode];
		// 队列顶部元素出队列，释放标记
		que.pop();
		mark[start[edge]] = false;
		// 枚举该顶点的所有出边（出度） 
		while (edge != -1) {
			if (dis[end[edge]] > dis[start[edge]] + weight[edge]) {
				dis[end[edge]] = dis[start[edge]] + weight[edge];
				route[end[edge]] = start[edge]; // 更新路径节点信息 
				// 更新完成，将更新的顶点加入队列 
				if (!mark[end[edge]]) {
					que.push(end[edge]);
					mark[end[edge]] = true;
					count_[end[edge]]++;
					// 如果某个顶点入队列次数大于图的顶点总数，
					// 那么这个图肯定存在负环，
					// 注意这里图的顶点编号为 1~n，因此是 count_[end[edge]] >= n  
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
	int n, m, s = 1; // 图的顶点数、边数，最短路径的源节点编号 
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> start[i] >> end[i] >> weight[i];
		next[i] = first[start[i]];
		first[start[i]] = i;
	}
	if (!spfa(1, n)) {
		cout << "该图存在负环！" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cout << dis[i] << " ";
	}
	
	cout << endl;
	int currentNode;
	for (int i = 1; i <= n; i++) {
		cout << "源节点到顶点 " << i << " 的路径信息： ";
		// 因为最短路径储存顺序是逆序的，那么需要用栈来将顺序调整过来 
		stack<int> stk;
		stk.push(i);
		currentNode = route[i];
		while (currentNode != s) {
			stk.push(currentNode);
			currentNode = route[currentNode];
		}
		stk.push(s);
		// 顺序出栈，输出路径信息： 
		int t = -1;
		while (!stk.empty()) {
			if (t != -1) {
				cout << "-->";
			}
			t = stk.top();
			stk.pop();
			cout << t;
		}
		cout <<"     距离：" << dis[i] << endl;
	}
	
	return 0;
}
