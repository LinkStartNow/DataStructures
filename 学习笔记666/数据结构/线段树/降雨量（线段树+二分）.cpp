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

const ll N = 5e4 + 7;
int s[N], n, year[N];
map<int, int> mp;
int ma[N << 2];

void build(int i, int l, int r)
{
    ma[i] = 0;
    if(l == r)
    {
        ma[i] = s[l];
        return;
    }
    int x(i), y(i), m(l, r);
    build(x, l, m), build(y, m + 1, r);
    ma[i] = max(ma[x], ma[y]);
}

int find(int i, int l, int r, int ln, int rn)
{
    if(l > rn || r < ln)
        return 0;
    if(l >= ln && r <= rn)
        return ma[i];
    int x(i), y(i), m(l, r);
    return max(find(x, l, m, ln, rn), find(y, m + 1, r, ln, rn));
}

int yyds(int x, bool f)
{
    if(f)
    {
        int l = 1, r = n;
        while(l <= r)
        {
            int m = (l + r) >> 1;
            if(year[m] >= x)
                r = m - 1;
            else
                l = m + 1;
        }
        return l == n + 1 ? 0 : l;
    }
    else
    {
        int l = 1, r = n;
        while(l <= r)
        {
            int m = (l + r) >> 1;
            if(year[m] <= x)
                l = m + 1;
            else
                r = m - 1;
        }
        return r;
    }
}

void solve()
{
    cin >> n;
    run(i, 1, n)
    {
        cin >> year[i] >> s[i];
        mp[year[i]] = i;
    }
    build(1, 1, n);
    int q;
    cin >> q;
    run(i, 1, q)
    {
        ll x, y;
        cin >> y >> x;
        if(y >= x)
        {
            cout << "false" << '\n';
            continue;
        }
        if(!mp[x] && !mp[y])
        {
            cout << "maybe" << '\n';
            continue;
        }
        if(mp[x] && mp[y])
        {
            if(s[mp[x]] > s[mp[y]])
            {
                cout << "false" << '\n';
                continue;
            }
            int l = yyds(y + 1, 1), r = yyds(x - 1, 0);
            if(l)
            {
                int f = find(1, 1, n, l, r);
                if(f >= s[mp[x]])
                {
                    cout << "false" << '\n';
                    continue;
                }
                if(r - l + 1 != x - y - 1)
                {
                    cout << "maybe" << '\n';
                    continue;
                }
                else
                {
                    cout << "true" << '\n';
                    continue;
                }
            }
            cout << "maybe" << '\n';
            continue;
        }
        if(mp[x])
        {
            int l = yyds(y + 1, 1), r = yyds(x - 1, 0);
            if(l)
            {
                int f = find(1, 1, n, l, r);
                if(f >= s[mp[x]])
                {
                    cout << "false" << '\n';
                    continue;
                }
                if(r - l + 1 != x - y - 1)
                {
                    cout << "maybe" << '\n';
                    continue;
                }
            }
            cout << "maybe" << '\n';
            continue;
        }
        else
        {
            int l = yyds(y + 1, 1), r = yyds(x - 1, 0);
            if(l)
            {
                int f = find(1, 1, n, l, r);
                if(f >= s[mp[y]])
                {
                    cout << "false" << '\n';
                    continue;
                }
                if(r - l + 1 != x - y - 1)
                {
                    cout << "maybe" << '\n';
                    continue;
                }
            }
            cout << "maybe" << '\n';
            continue;
        }
    }
}

int main() // https://www.luogu.com.cn/problem/P2471
{
    speed
//    t()
    solve();
    return 0;
}
