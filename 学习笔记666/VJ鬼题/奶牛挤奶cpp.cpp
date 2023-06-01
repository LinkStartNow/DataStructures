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
    friend bool operator<(Node a,Node b)   //Node�Ȱ��ս���ʱ����������տ�ʼʱ��������
    {
       if(a.en==b.en)
        return a.st<b.st;
       return a.en>b.en;
    }
}node[maxn];  //nodeװNode����

bool cmp(Node a,Node b)  //��st�Ⱥ�en
{
    if(a.st==b.st)
        return a.en<b.en;
    else
        return a.st<b.st;
}

priority_queue<Node>Q;  //�������ȶ���Q�洢Node

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
        sort(node+1,node+1+n,cmp); //������node��st��������
        ans=1;
        Q.push(node[1]);  //Q�����һͷţ
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
                ans++; //��Ҫ��������һ
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


