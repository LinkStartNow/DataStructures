#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))

using namespace std;
const ll N = 1e4 + 5;
ll p[N], d[N];
bool zero = 0;
int tot;

void init()
{
    ms(p), ms(d);
    tot = 0;
    zero = 0;
}

void add(ll x)
{
    rep(i, 62, 0)
    {
        if(x >> i & 1)
            if(p[i])
                x ^= p[i];
            else
            {
                p[i] = x;
                return;
            }
    }
    if(!x)
        zero = 1;
}
void rebuild()
{
    rep(i, 62, 0)
    if(p[i])
        rep(j, i - 1, 0)
        if(p[i] >> j & 1)
            p[i] ^= p[j];
    run(i, 0, 62)
    if(p[i])
        d[++ tot] = p[i];
}
ll getk(ll k)
{
    if(k >= (1ll << tot))
        return -1;
    ll ans = 0;
    run(i, 1, tot)
    {
        if(k & 1)
            ans ^= d[i];
        k >>= 1;
    }
    return ans;
}
int main()
{
    int ca, n, q;
    ll s;
    scanf("%d", &ca);
    run(i, 1, ca)
    {
        init();
        printf("Case #%d:\n", i);
        scanf("%d", &n);
        run(i, 1, n)
        {
            scanf("%lld", &s);
            add(s);
        }
        rebuild();
        scanf("%d", &q);
        while(q --)
        {
            scanf("%lld", &s);
            printf("%lld\n", getk(s - zero));
        }
    }
}
