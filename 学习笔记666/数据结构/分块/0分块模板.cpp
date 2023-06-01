#include<bits/stdc++.h>
#define run(i, a, b) for(long long i = a; i <= b; i ++)
#define ll long long
using namespace std;
const int N = 1e5 + 5;
ll a[N], b[1000], s[1000];
int st[1000], ed[1000];
int ad[N];
int n, m, len;
void add(int l, int r, ll v)
{
    int sid = ad[l], eid = ad[r];
    if(sid == eid)
    {
        run(i, l, r)
        {
            a[i] += v;
            s[sid] += v;
        }
        return;
    }
    for(int i = l; ad[i] == sid; i ++)
    {
        a[i] += v;
        s[sid] += v;
    }
    for(int i = sid + 1; i < eid; i ++)
    {
        s[i] += len * v;
        b[i] += v;
    }
    for(int i = r; ad[i] == eid; i --)
    {
        a[i] += v;
        s[eid] += v;
    }
}
ll query(int l, int r)
{
    ll ans = 0;
    int sid = ad[l], eid = ad[r];
    if(sid == eid)
    {
        run(i, l, r)
            ans += a[i] + b[sid];
        return ans;
    }
    for(int i = l; ad[i] == sid; i ++)
        ans += a[i] + b[sid];
    for(int i = sid + 1; i < eid; i ++)
        ans += s[i];
    for(int i = r; ad[i] == eid; i --)
        ans += a[i] + b[eid];
    return ans;
}
void init()
{
    run(i, 1, (n - 1) / len + 1)
    {
        st[i] = (i - 1) * len + 1;
        ed[i] = i * len;
    }
    ed[(n - 1) / len + 1] = n;
}
int main()
{
    cin >> n >> m;
    len = sqrt(n);
    run(i, 1, n)
    {
        scanf("%lld", &a[i]);
        ad[i] = (i - 1) / len + 1;
        s[ad[i]] += a[i];
    }
    init();
    while(m --)
    {
        int k;
        scanf("%d", &k);
        if(k == 1)
        {
            int l, r;
            ll v;
            scanf("%d%d%lld", &l, &r, &v);
            add(l, r, v);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(l, r));
        }
    }
}
