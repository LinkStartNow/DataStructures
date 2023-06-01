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
const int N = 1e5 + 7;
int n, m;
vector<int> v[N];
int in[N], out[N], cnt0 = 0, cnt1 = 0, s = 1;
int ans[N << 1], tot, vis[N];

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
    for(int i = vis[x]; i < v[x].size(); i = vis[x])
    {
        vis[x] ++;
        int to = v[x][i];
        dfs(to);
    }
    ans[++ tot] = x;
}

void solve()
{
    cin >> n >> m;
    run(i, 1, m)
    {
        int a, b;
        cin >> a >> b;
        in[b] ++, out[a] ++;
        v[a].push_back(b);
    }
    bool f = 0;
    run(i, 1, n)
    {
        sort(v[i].begin(), v[i].end());
        if(in[i] != out[i])
        {
            f = 1;
            if(out[i] - in[i] == 1)
            {
                s = i;
                cnt0 ++;
            }
            if(in[i] - out[i] == 1)
                cnt1 ++;
        }
    }
    if(f && !(cnt0 == 1 && cnt1 == 1))
        cout << "No" << '\n';
    else
    {
        dfs(s);
        rep(i, tot, 1)
        cout << ans[i] << ' ';
        cout << '\n';
    }
}
int main() //https://www.luogu.com.cn/problem/P7771
{
    speed
//    t()
    solve();
    return 0;
}
