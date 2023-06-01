#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int fa[N],d[N];
int yyds(int x)
{
    if(x == fa[x])
        return x;
    int p = yyds(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = p;
}
int main()
{
    int n,k;
    int a,b,m;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0; i <= n; i ++)
        {
            d[i] = 0;
            fa[i] = i;
        }
        while(n --)
        {
            scanf("%d",&k);
            if(k == 1)
            {
                scanf("%d%d%d",&a,&b,&m);
                int x = yyds(a),y = yyds(b);
                if(x != y)
                {
                    fa[y] = x;
                    d[y] = d[a] + m - d[b];
                }
            }
            else
            {
                scanf("%d%d",&a,&b);
                int x = yyds(a),y = yyds(b);
                if(x != y)
                    printf("?\n");
                else
                    printf("%d\n",d[b] - d[a]);
            }
        }
    }
    return 0;
}
