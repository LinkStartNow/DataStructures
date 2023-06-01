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
        int k = 0;
        run(i, l, ed[sid])
        {
            if(i <= r)
                k ++;
            p[i] += v * k;
        }
        ll vs = v * k;
        run(i, sid, id[n])
            pro[i] += vs;
    }
    else
    {
        int k = 0;
        run(i, l, ed[sid])
        {
            k ++;
            p[i] += v * k;
        }
        k = 0;
        run(i, sid + 1, eid - 1)
        {
            b[i] += v;
        }
        run(i, st[eid], ed[eid])
        {
            if(i <= r)
                k ++;
            p[i] += v * k;
        }
        ll vs = 0;
        run(i, sid, id[n])
        {
            if(i == sid)
                vs += v * (ed[i] - l + 1);
            else if(i < eid)
                vs += v * (ed[i] - st[i] + 1);
            if(i == eid)
                vs += v * (r - st[eid] + 1);
            pro[i] += vs;
        }
    }
}
ll query(int l, int r)
{
    int sid = id[l], eid = id[r];
    if(sid == eid)
    {
        if(id[l] == id[l - 1])
            return p[r] - p[l - 1] + (ll)b[sid] * (r - l + 1);
        return p[r] + (ll)b[sid] * (r - l + 1);
    }
    ll ans = 0;
    if(id[l] == id[l - 1])
        ans += p[ed[sid]] - p[l - 1] + (ll)b[sid] * (ed[sid] - l + 1);
    else
        ans += p[ed[sid]] + (ll)b[sid] * (ed[sid] - l + 1);
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
