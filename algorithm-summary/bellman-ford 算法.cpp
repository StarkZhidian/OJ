
#include <iostream>
#include <stack>
using namespace std;
#define MAX 10000  // 假设权值最大不超过 10000

struct Edge
{
    int u;
    int v;
    int w;
};

Edge edge[10000]; // 记录所有边
int  dist[100];   // 源点到顶点 i 的最短距离
int  path[100];   // 记录最短路的路径
int  vertex_num;  // 顶点数
int  edge_num;    // 边数
int  source;      // 源点

bool BellmanFord()
{
    // 初始化
    for (int i = 0; i < vertex_num; i++)
        dist[i] = (i == source) ? 0 : MAX;

    // n-1 次循环求最短路径
    for (int i = 1; i <= vertex_num - 1; i++)
    {
        for (int j = 0; j < edge_num; j++)
        {
            if (dist[edge[j].v] > dist[edge[j].u] + edge[j].w)
            {
                dist[edge[j].v] = dist[edge[j].u] + edge[j].w;
                path[edge[j].v] = edge[j].u;
            }
        }
    }
    bool flag = true;  // 标记是否有负权回路
    // 第 n 次循环判断负权回路
    for (int i = 0; i < edge_num; i++)
    {
        if (dist[edge[i].v] > dist[edge[i].u] + edge[i].w)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

void Print()
{
    for (int i = 0; i < vertex_num; i++)
    {
        if (i != source)
        {
            int p = i;
            stack<int> s;
            cout << "顶点 " << source << " 到顶点 " << p << " 的最短路径是： ";

            while (source != p)  // 路径顺序是逆向的，所以先保存到栈
            {
                s.push(p);
                p = path[p];
            }

            cout << source;
            while (!s.empty())  // 依次从栈中取出的才是正序路径
            {
                cout << "--" << s.top();
                s.pop();
            }
            cout << "    最短路径长度是：" << dist[i] << endl;
        }

    }
}

int main()
{
    cout << "请输入图的顶点数，边数，源点：";
    cin >> vertex_num >> edge_num >> source;
    cout << "请输入" << edge_num << "条边的信息：\n";
    for (int i = 0; i < edge_num; i++)
        cin >> edge[i].u >> edge[i].v >> edge[i].w;
    if (BellmanFord())
        Print();
    else
        cout << "Sorry,it have negative circle!\n";

    return 0;
}
