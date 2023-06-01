#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int dp[N][N], key[N][N];
int a[N], b[N], na, nb, val, k;
void pri(int i, int j)
{
    if(i == 0 || j == 0)
        return;
    bool f = false;
    int l;
    for(l = i; l >= 1; l --)
    {
        if(a[l] == b[j])
        {
            f = true;
            break;
        }
    }
    if(f)
    {
        pri(l - 1, key[i][j]);
        printf("%d ", a[l]);
    }
}
int main()
{
    scanf("%d", &na);
    for(int i = 1; i <= na; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &nb);
    for(int i = 1; i <= nb; i ++)
        scanf("%d", &b[i]);
    for(int i = 1; i <= na; i ++)
    {
        val = 0, k = 0;
        for(int j = 1; j <= nb; j ++)
        {
            if(a[i] == b[j])
            {
                dp[i][j] = val + 1;
                key[i][j] = k;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                key[i][j] = key[i - 1][j];
            }
            if(b[j] < a[i])
            {
                if(dp[i][j] > val)
                    k = j;
                val = max(val, dp[i][j]);
            }
        }
    }
    k = 1;
    for(int i = 2; i <= nb; i ++)
        if(dp[na][i] > dp[na][k])
            k = i;
    printf("%d\n", dp[na][k]);
    pri(na, k);
    printf("\n");
}
