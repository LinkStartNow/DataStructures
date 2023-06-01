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

const int N = 3e6 + 7;
struct zly
{
    int v, id;
} a[N];
stack<zly> yi;
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


void solve()
{
    int n;
    cin >> n;
    run(i, 1, n)
        cin >> a[i].v, a[i].id = i;
    rep(i, n, 1)
    {
        bool f = 0;
        while(!yi.empty())
        {
            if(a[i].v >= yi.top().v)
                yi.pop();
            else
            {
                ans.push(yi.top().id);
                yi.push(a[i]);
                f = 1;
                break;
            }
        }
        if(!f)
            ans.push(0), yi.push(a[i]);
    }
    while(!ans.empty())
    {
        cout << ans.top() << ' ';
        ans.pop();
    }
}
int main() //https://www.luogu.com.cn/problem/P5788
{
    speed
//    t()
    solve();
    return 0;
}
