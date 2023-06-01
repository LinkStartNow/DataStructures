#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)

using namespace std;
const int N = 605;
ll n, p;
ll a[N][N];
ll yyds()
{
    ll ans = 1;
    run(c, 1, n)
    {
        run(i, c + 1, n)
        {
            while(a[i][c])
            {
                ll k = a[c][c] / a[i][c];
                run(j, c, n)
                    a[c][j] = (a[c][j] - k * a[i][j]) % p;
                run(j, c, n)
                    swap(a[c][j], a[i][j]);
                ans = - ans;
            }
        }
        if(!a[c][c])
            return 0;
    }
    run(i, 1, n)
        ans = (ans * a[i][i]) % p;
    return (ans + p) % p;
}
int main()
{
    scanf("%lld%lld", &n, &p);
    run(i, 1, n)
    run(j, 1, n)
    {
        scanf("%lld", &a[i][j]);
        a[i][j] %= p;
    }
    printf("%lld\n", yyds());
}
