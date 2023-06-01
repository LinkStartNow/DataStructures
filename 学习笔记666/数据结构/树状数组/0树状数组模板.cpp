#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, q, k;
long long t1[N], t2[N];
int lowbit(int i)
{
    return i & (- i);
}
void add(int i, int v)
{
    long long vs = (long long)v * i;
    while(i <= n)
    {
        t1[i] += (long long)v;
        t2[i] += (long long)vs;
        i += lowbit(i);
    }
}
void adds(int l, int r, int v)
{
    add(l, v), add(r + 1, -v);
}
long long getsum(long long *t, int i)
{
    long long ans = 0;
    while(i)
    {
        ans += t[i];
        i -= lowbit(i);
    }
    return ans;
}
long long getsums(int l, int r)
{
    return getsum(t1, r) * (r + 1) - getsum(t2, r) - (getsum(t1, l - 1) * l - getsum(t2, l - 1));
}
int main()
{
    scanf("%d%d", &n, &q);
    int p;
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d", &p);
        adds(i, i, p);
    }
    while(q --)
    {
        int x, y, z;
        scanf("%d", &k);
        if(k == 1)
        {
            scanf("%d%d%d", &x, &y, &z);
            adds(x, y, z);
        }
        else
        {
            scanf("%d%d", &x, &y);
            printf("%lld\n", getsums(x, y));
        }
    }
}
