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

const int N = 307;
int mi[N][N], ma[N][N];
int ansa = 1e9, ansb;
int s[N];
int n;

void dp()
{
    run(i, 1, n << 1)
        mi[i][i] = ma[i][i] = 0;
    run(len, 2, 1 << n)
    {
        run(l, 1, n << 1)
        {
            int r = l + len - 1;
            if(r > 2 * n)
                break;
            mi[l][r] = 1e9;
            int ssr = s[r] - s[l - 1];
            run(k, l, r - 1)
            {
                mi[l][r] = min(mi[l][r], mi[l][k] + mi[k + 1][r]);
                ma[l][r] = max(ma[l][r], ma[l][k] + ma[k + 1][r]);
            }
            mi[l][r] += ssr, ma[l][r] += ssr;
        }
    }
}

int dfsi(int l, int r)
{
    if(mi[l][r])
        return mi[l][r];
    if(l == r)
        return mi[l][r] = 0;
    mi[l][r] = 1e9;
    run(k, l, r - 1)
        mi[l][r] = min(mi[l][r], dfsi(l, k) + dfsi(k + 1, r));
    return mi[l][r] += s[r] - s[l - 1];
}

int dfsa(int l, int r)
{
    if(ma[l][r])
        return ma[l][r];
    if(l == r)
        return ma[l][r] = 0;
    run(k, l, r - 1)
        ma[l][r] = max(ma[l][r], dfsa(l, k) + dfsa(k + 1, r));
    return ma[l][r] += s[r] - s[l - 1];
}

void solve()
{
    cin >> n;
    run(i, 1, n)
        cin >> s[i], s[i + n] = s[i];
    run(i, 1, n << 1)
        s[i] += s[i - 1];
    dp();
//    dfsa(1, n << 1), dfsi(1, n << 1);
    run(i, 1, n)
        ansa = min(ansa, mi[i][i + n - 1]), ansb = max(ansb, ma[i][i + n - 1]);
    printf("%d\n%d", ansa, ansb);
}

int main() // https://www.luogu.com.cn/problem/P1880
{
    speed
//    t()
    solve();
    return 0;
}
