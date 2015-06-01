#include<bits/stdc++.h>

#define INF 2100000000
using namespace std;

bool visited[210];
int flowArray[210], pathArray[210];
int edge[210][210], baki[210][210];
int n;

int BFS(int s, int t)
{
    memset(visited, 0 , sizeof(visited));
    memset(pathArray, 0, sizeof(pathArray));
    memset(flowArray, 0, sizeof(flowArray));
    flowArray[s] = INF;
    visited[s] = 1;
    queue <int> Q;
    Q.push(s);
    int i, j;
    while (!Q.empty())
    {
        i = Q.front();
        Q.pop();
        for (j = 1; j <= 2*n+1; j++)
        {
            if (!visited[j] && baki[i][j] > 0)
            {
                visited[j] = 1;
                flowArray[j] = min(flowArray[i], baki[i][j]);
                pathArray[j] = i;
                Q.push(j);
                if (j == t) return flowArray[t];
            }
        }
    }
    return flowArray[t];
}

int main()
{
    //freopen("in.txt","r",stdin);

    int  m,a,b,d,capacity,i,j;
    while (scanf("%d", &n) != EOF)
    {
        memset(edge, 0, sizeof(edge));
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &capacity);
            edge[i][i+n] += capacity;
        }
        scanf("%d", &m);
        for (i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &a, &b, &capacity);
            edge[a+n][b] += capacity;
        }
        scanf("%d %d", &b, &d);
        for (i = 1; i <= b; i++)
        {
            scanf("%d", &a);
            edge[0][a] = INF; //entry points set as infinity
        }
        for (i = 1; i <= d; i++)
        {
            scanf("%d", &a);
            edge[a+n][2*n+1] = INF; // ending point to super sink set as infinity
            edge[a+n][2*n+1] = INF; // ending point to super sink set as infinity
        }
        //printf("%d\n", maxflow(0, 2*n+1));



        //edmond-karp
        memcpy(baki, edge, sizeof(edge));


        int flow=0, dif,s=0,t=2*n+1;
        while(dif = BFS(s, t))
        {
            for (i = pathArray[t], j = t; i != j; i = pathArray[j = i])
            {
                baki[i][j] = baki[i][j]-dif;
                baki[j][i] = baki[j][i]+dif;

            }
            flow =flow+ dif;
        }
        printf("%d\n", flow);
    }
    return 0;
}
