#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 5;
int f[N],ans;
int yyds(int x) {return x == f[x] ? x : f[x] = yyds(f[x]);}
int main()
{
    int n,m,a,b;
    cin >> n >> m;
    for(int i = 0; i < n; i ++)
        f[i] = i;
    while(m --)
    {
        scanf("%d%d",&a,&b);
        if(yyds(a) != yyds(b))
            f[yyds(a)] = yyds(b);
    }
    for(int i = 0; i < n; i ++)
        if(yyds(i) == yyds(0))
            ans ++;
    printf("%d\n",ans);
}
