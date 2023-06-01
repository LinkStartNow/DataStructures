#include<bits/stdc++.h>

#define ll long long
#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define run(i, a, b) for(int i = a; i <= b; i ++)

using namespace std;

const int N = 2e7 + 5;

int nxt[N], exi[N];
char s[N], t[N];
int ls, lt;
void getnxt()
{
    lt = strlen(t + 1);
    nxt[1] = lt;
    int a = 1, p = 1;
    run(i, 2, lt)
    {
        if(i <= p)
            nxt[i] = min(p - i + 1, nxt[i - a + 1]);
        while(nxt[i] < lt && t[i + nxt[i]] == t[nxt[i] + 1])
            nxt[i] ++;
        if(i + nxt[i] - 1 > p)
        {
            a = i;
            p = i + nxt[i] - 1;
        }
    }
}
void z()
{
    ls = strlen(s + 1);
    int a = 0, p = 0;
    run(i, 1, ls)
    {
        if(i <= p)
            exi[i] = min(p - i + 1, nxt[i - a + 1]);
        while(exi[i] <= ls && exi[i] <= lt && s[exi[i] + i] == t[exi[i] + 1])
            exi[i] ++;
        if(i + exi[i] - 1 > p)
        {
            a = i;
            p = i + exi[i] - 1;
        }
    }
}
void check(char *s, int *t)
{
    int len = strlen(s + 1);
    run(i, 1, len)
        printf("%d ", t[i]);
}
int main()
{
    scanf("%s%s", s + 1, t + 1);
    getnxt();
    z();
    check(t, nxt);
}
