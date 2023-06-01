#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const ll N = 1e5 + 7;

int f[N], ssr[N], g[N];

int fa(int x)
{
    if(f[x] == x)
        return x;
    int ft = f[x], fc = fa(ft);
    ssr[x] += ssr[ft];
    return f[x] = fc;
}

void solve()
{
    int n;
    cin >> n;
    run(i, 1, 3e4)
        f[i] = i, g[i] = 1;
    run(i, 1, n)
    {
        char s[5];
        int a, b;
        cin >> s >> a >> b;
        if(s[0] == 'M')
        {
            int x = fa(a), y = fa(b);
            ssr[x] += g[y];
            g[y] += g[x];
            f[x] = y;
        }
        else
        {
            if(fa(a) != fa(b))
                cout << "-1" << '\n';
            else
                cout << abs(ssr[a] - ssr[b]) - 1 << '\n';
        }
    }
}

int main() // https://www.luogu.com.cn/problem/P1196
{
    speed
//    t()
    solve();
    return 0;
}
