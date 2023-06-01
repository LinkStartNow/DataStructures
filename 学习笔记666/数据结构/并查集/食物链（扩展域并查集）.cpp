#include<cstdio>
using namespace std;
const int N = 5e4 + 5;
int fa[N * 3];
int ff(int x)
{
    return x == fa[x] ? x : fa[x] = ff(fa[x]);
}
int main()
{
    int n, k;
    int d, x, y;
    int ans = 0;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= 3 * n; i ++)
        fa[i] = i;
    while(k --)
    {
        scanf("%d%d%d", &d, &x, &y);
        if(x > n || y > n)
        {
            ans ++;
            continue;
        }
        if(d == 1)
        {
            if(ff(x) == ff(y + n) || ff(x + n) == ff(y))
            {
                ans ++;
                continue;
            }
            fa[ff(y)] = ff(x);
            fa[ff(y + n)] = ff(x + n);
            fa[ff(y + 2 * n)] = ff(x + 2 * n);
        }
        else
        {
            if(ff(x + n) == ff(y) || ff(x) == ff(y))
            {
                ans ++;
                continue;
            }
            fa[ff(y + n)] = ff(x);
            fa[ff(y + 2 * n)] = ff(x + n);
            fa[ff(y)] = ff(x + 2 * n);
        }
    }
    printf("%d\n", ans);
}
