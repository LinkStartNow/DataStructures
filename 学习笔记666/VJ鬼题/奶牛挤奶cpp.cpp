#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=50000+10;
int order[maxn];

struct Node
{
    int st,en,pos;
    friend bool operator<(Node a,Node b)   //Node先按照结束时间早排序后按照开始时间早排序
    {
       if(a.en==b.en)
        return a.st<b.st;
       return a.en>b.en;
    }
}node[maxn];  //node装Node类型

bool cmp(Node a,Node b)  //按st先后en
{
    if(a.st==b.st)
        return a.en<b.en;
    else
        return a.st<b.st;
}

priority_queue<Node>Q;  //定义优先队列Q存储Node

int main()
{
    int n,ans;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&node[i].st,&node[i].en);
            node[i].pos=i;
        }
        sort(node+1,node+1+n,cmp); //对数组node按st优先排序
        ans=1;
        Q.push(node[1]);  //Q存入第一头牛
        order[node[1].pos]=1;
        for(int i=2;i<=n;i++)
        {
            if(!Q.empty()&&Q.top().en<node[i].st)
            {
               order[node[i].pos]=order[Q.top().pos];
               Q.pop();
            }
            else
            {
                ans++; //需要的数量加一
                order[node[i].pos]=ans;
            }
            Q.push(node[i]);
        }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++)
            printf("%d\n",order[i]);
        while(!Q.empty())  Q.pop();
    }
    return 0;
}


