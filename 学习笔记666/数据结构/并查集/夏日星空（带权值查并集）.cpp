#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+6;
const int M = 1e6+6;
long long fa[N],dx[N],dy[N],n,m;
string s;
string dir;
long long yyds(long long x)
{
    if(x == fa[x])
        return x;
    long long p = yyds(fa[x]);
    dx[x] += dx[fa[x]];
    dy[x] += dy[fa[x]];
    return fa[x] = p;
}
int main()
{
    long long k,l,a,b;
    while(cin >> n >> m)
    {
        for(long long i = 1; i <= n; i ++)
        {
            dx[i] = dy[i] = 0;
            fa[i] = i;
        }
        while(m --)
        {
            cin >> s;
            if(s[0] == 'A')
            {
                cin >> a >> b >> l >> dir;
                long long x,y;
                long long c = yyds(a),d = yyds(b);
                fa[d] = c;
                x = y = 0;
                if(dir[0] == 'U')
                {
                    y = l;
                }
                else if(dir[0] == 'D')
                {
                    y = -l;
                }
                else if(dir[0] == 'R')
                {
                    x = l;
                }
                else
                {
                    x = -l;
                }
                dx[d]=-dx[b]+dx[a]+x;
                dy[d]=-dy[b]+dy[a]+y;
            }
            else
            {
                cin >> a >> b;
                long long x = yyds(a),y = yyds(b);
                if(x != y)
                    puts("-1");
                else
                    cout << (abs(dx[a] - dx[b]) + abs(dy[a] - dy[b])) << endl;
            }
        }
    }
    return 0;
}
