#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(ll i = a; i <= b; i ++)
#define rep(i, a, b) for(ll i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))

using namespace std;
const ll p = 1e9 + 7;
ll pows(ll x, ll y)
{
    ll ans = 1;
    while(y)
    {
        if(y & 1)
            ans = ans * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return ans;
}
ll fermat(ll x, ll mod)
{
    return pows(x, mod - 2);
}
ll gcd(ll a,ll b,ll &x,ll &y){
    if (b==0){
        x=1,y=0;
        return a;
    }
    ll q=gcd(b,a%b,y,x);
    y-=a/b*x;
    return q;
}

ll expe(ll x, ll mod)
{
    ll xx, yy;
    gcd(x, mod, xx, yy);
    return xx;
}
int main()
{
    ll k, n;
    cin >> n >> k;
    ll a = 1;
    run(i, 1, n)
        a = a * i % p;
    ll b = a, c = a * (n + 1) % p;
    run(i, n + 1, 2 * n)
        a = a * i % p;
    ll num = pows(k, n);
    ll invb = expe(b, p), invc = expe(c, p);
    ll ans = a * invb % p * invc % p * num % p;
    cout << ans;
}
