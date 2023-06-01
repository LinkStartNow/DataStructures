#include<bits/stdc++.h>

#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define run(i, a, b) for(int i = a; i <= b; i ++)

using namespace std;

const int N = 1.1e7 + 5;

char s[N], sn[2 * N];
int sl[2 * N];
int l, ln;

void init()
{
    l = strlen(s + 1);
    ln = 2;
    sn[0] = '$';
    sn[1] = '#';
    run(i, 1, l)
    {
        sn[ln ++] = s[i];
        sn[ln ++] = '#';
    }
    sn[ln] = '\0';
}
void expend(int i)
{
    int l = i - sl[i], r = i + sl[i];
    while(sn[l] == sn[r])
    {
        l --, r ++;
        sl[i] ++;
    }
}
void manancher()
{
    init();
    int id = 0, r = 0;
    run(i, 1, ln - 1)
    {
        int j = id * 2 - i;
        if(i < r)
            sl[i] = min(r - i, sl[j]);
        else
            sl[i] = 1;
        expend(i);
        if(i + sl[i] > r)
        {
            id = i;
            r = i + sl[i];
        }
    }
}
int main()
{
    scanf("%s", s + 1);
    manancher();
    int ans = 0;
    run(i, 2, ln)
    {
        ans = max(ans, sl[i] - 1);
    }
    printf("%d\n", ans);
}
