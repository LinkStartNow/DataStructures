#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) mid = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;
const int N = 507;
int n, m;
int dg[N], e[N][N];
stack<int> ans;

ll spow(ll x, ll y)
{
    ll res = 1;
    while(y)
    {
        if(y & 1)
            res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}

ll lowbit(ll x)
{
    return x & -x;
}

void dfs(int x)
{
    run(i, 1, 500)
    {
        if(e[x][i])
        {
            e[x][i] --;
            e[i][x] --;
            dfs(i);
        }
    }
    ans.push(x);
}

void solve()
{
    cin >> n;
    run(i, 1, n)
    {
        int a, b;
        cin >> a >> b;
        e[a][b] ++;
        e[b][a] ++;
        dg[a] ++, dg[b] ++;
    }
    int s = -1;
    run(i, 1, 500)
    if(dg[i] & 1)
    {
        s = i;
        break;
    }
    if(s == -1)
        run(i, 1, 500)
        if(dg[i])
        {
            s = i;
            break;
        }
    dfs(s);
    while(!ans.empty())
    {
        cout << ans.top() << '\n';
        ans.pop();
    }
}
int main() //https://www.luogu.com.cn/problem/P2731
{
    speed
//    t()
    solve();
    return 0;
}
