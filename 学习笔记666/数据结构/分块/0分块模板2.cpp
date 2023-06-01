#include<bits/stdc++.h>
#define run(i, a, b) for(long long i = a; i <= b; i ++)
#define ll long long
#define m(l, r) mid = (l + r) >> 1
using namespace std;
const int N = 1e5 + 5;
int n, m, len;
ll a[N], s[1000], b[1000], p[N], pro[1000];
ll id[N], st[1000], ed[1000];
void pre()
{
    run(i, 1, n)
    {
        if(id[i] != id[i - 1])
            p[i] = a[i];
        else
            p[i] = p[i - 1] + a[i];
    }
    run(i, 1, id[n])
    pro[i] = pro[i - 1] + s[i];
}
void update(int l, int r, ll v)
{
    int sid = id[l], eid = id[r];
    if(sid == eid)
    {
        run(i, l, ed[sid])
        {
            if(i <= r)
            {
                a[i] += v;
                s[id[i]] += v;
            }
            if(id[i] != id[i - 1])
                p[i] = a[i];
            else
                p[i] = p[i - 1] + a[i];
        }
        run(i, 1, id[n])
        pro[i] = pro[i - 1] + s[i];
    }
    else
    {
        run(i, l, ed[sid])
        {
            a[i] += v, s[sid] += v;
            if(id[i] != id[i - 1])
                p[i] = a[i];
            else
                p[i] = p[i - 1] + a[i];
        }
        run(i, st[eid], ed[eid])
        {
            if(i <= r)
                a[i] += v, s[eid] += v;
            if(id[i] != id[i - 1])
                p[i] = a[i];
            else
                p[i] = p[i - 1] + a[i];
        }
        run(i, sid + 1, eid - 1)
        b[i] += v, s[i] += v * len;
        run(i, 1, id[n])
        pro[i] = pro[i - 1] + s[i];
    }
}
ll query(int l, int r)
{
    int sid = id[l], eid = id[r];
    if(sid == eid)
        return p[r] - p[l] + a[l] + (ll)b[sid] * (r - l + 1);
    ll ans = 0;
    ans += p[ed[sid]] - p[l] + a[l] + (ll)b[sid] * (ed[sid] - l + 1);
    ans += p[r] + (ll)b[eid] * (r - st[eid] + 1);
    ans += pro[eid - 1] - pro[sid];
    return ans;
}
int main()
{
    cin >> n >> m;
    len = sqrt(n);
    run(i, 1, n)
    {
        scanf("%lld", &a[i]);
        id[i] = (i - 1) / len + 1;
        s[id[i]] += a[i];
    }
    run(i, 1, (n - 1) / len + 1)
    {
        st[i] = (i - 1) * len + 1;
        ed[i] = i * len;
    }
    ed[(n - 1) / len + 1] = n;
    pre();
    int k;
    while(m --)
    {
        scanf("%d", &k);
        if(k == 1)
        {
            int l, r;
            ll v;
            scanf("%d%d%lld", &l, &r, &v);
            update(l, r, v);
        }
        else
        {
            int l, r;
            scanf("%d%d", &l, &r);
            printf("%lld\n", query(l, r));
        }
    }
}
