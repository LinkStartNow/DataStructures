#include<bits/stdc++.h>
using namespace std;
const int p = 131, mod = 1e9 + 9, N = 1e6 + 5;
long long pr[N];
char s[N], st[N];
long long h[N], ht[N];
int l, lt, cnt;
void init()
{
    pr[0] = 1;
    for(int i = 1; i <= N; i ++)
        pr[i] = pr[i - 1] * p % mod;
}
void Hash(char *s, long long *h)
{
    l = strlen(s + 1);
    for(int i = 1; i <= l; i ++)
        h[i] = (h[i - 1] * p + s[i]) % mod;
}
int strs(int l, int r, long long *ho)
{
    return (ho[r] - ho[l - 1] * pr[r - l + 1] % mod + mod) % mod;
}
bool check(int m, int r1)
{
    if(strs(r1 - m + 1, r1, h) == strs(1, m, ht))
        return true;
    return false;
}
int find()
{
    l = strlen(s + 1), lt = strlen(st + 1);
    int ans = 0;
    for(int i = 1; i <= l && i <= lt; i ++)
    {
        if(check(i, l))
            ans = max(ans, i);
    }
    return ans;
}
void mergehash(int len)
{
    l = strlen(st + 1);
    for(int i = cnt + 1; i <= cnt + l - len; i ++)
    {
        h[i] = (h[i - 1] * p + st[len + i - cnt]) % mod;
        s[i] = st[len + i - cnt];
    }
    cnt += l - len;
}
int main()
{
    init();
    int n;
    scanf("%d", &n);
    scanf("%s", s + 1);
    Hash(s, h);
    cnt = strlen(s + 1);
    for(int i = 1; i < n; i ++)
    {
        scanf("%s", st + 1);
        Hash(st, ht);
        int c = find();
        mergehash(c);
    }
    printf("%s\n", s + 1);
}
