#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int f[N], d[N], p[N][2];
int t, n, m;
string s;
int fa(int x)
{
    if(f[x] == x)
        return x;
    int ff = f[x];
    f[x] = fa(ff);
    d[x] = (d[x] + d[ff]) % 2;
    return f[x];
}
int main()
{
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++)
        {
            f[i] = i;
            d[i] = 0;
            p[i][1] = p[i][0] = 0;
        }
        bool flag = 1;
        while(m --)
        {
            int u, v;
            cin >> u >> v >> s;
            if(s[0] == 'c')
            {
                int x = fa(u), y = fa(v);
                if(x == y && d[u] != d[v])
                {
                    flag = 0;
                    continue;
                }
                if(x == y)
                    continue;
                f[x] = v;
                d[x] = d[u] % 2;
            }
            else
            {
                int x = fa(u), y = fa(v);
                if(x == y && d[u] == d[v])
                {
                    flag = 0;
                    continue;
                }
                if(x == y)
                    continue;
                f[x] = v;
                d[x] = (1 + d[u]) % 2;
            }
        }
        if(!flag)
            printf("-1\n");
        else
        {
            int ans = 0;
            for(int i = 1; i <= n; i ++)
                p[fa(i)][d[i]] ++;
            for(int i = 1; i <= n; i ++)
                ans += max(p[i][0], p[i][1]);
            printf("%d\n", ans);
        }
    }
}
