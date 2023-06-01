#include<cstdio>
#include<iostream>
using namespace std;
const int N = 1005;
int a[N],c[10005],f[N];
inline int lowbit(int x)
{
    return x & (- x);
}
int find(int x)
{
    int ans = 0;
    while(x)
    {
        ans = max(ans, c[x]);
        x -= lowbit(x);
    }
    return ans;
}
void yyds(int k, int ma)
{
    while(k <= 10001)
    {
        c[k] = max(c[k], ma);
        k += lowbit(k);
    }
}
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        scanf("%d", &a[i]);
        a[i] ++;
    }
    for(int i = 1; i <= n; i ++)
    {
        f[i] = 1 + find(a[i] - 1);
        ans = max(ans, f[i]);
        yyds(a[i], f[i]);
    }
    printf("%d\n", ans);
}
