#include<cstdio>
#include<cstring>

#define run(i, a, b) for(int i = a; i <= b; i ++)

using namespace std;
const int N = 65;
char s[15][N];
char ans[N], tmp[N], res[N];
int kmp[N], len;
int n;
void getkmp(char *s)
{
    len = strlen(s + 1);
    int j = 0;
    run(i, 2, len)
    {
        while(j && s[j + 1] != s[i])
            j = kmp[j];
        if(s[j + 1] == s[i])
            j ++;
        kmp[i] = j;
    }
}
bool Kmp(char *s)
{
    len = strlen(s + 1);
    int ll = strlen(tmp + 1);
    int j = 0;
    run(i, 1, len)
    {
        while(j && s[i] != tmp[j + 1])
            j = kmp[j];
        if(s[i] == tmp[j + 1])
            j ++;
        if(j == ll)
        {
            strcpy(res + 1, tmp + 1);
            return 1;
        }
    }
    return 0;
}
int main()
{
    n = 60;
    int t;
    scanf("%d", &t);
    while(t --)
    {
        memset(kmp, 0, sizeof(kmp));
        memset(ans, 0, sizeof(ans));
        int m;
        scanf("%d", &m);
        run(i, 1, m)
            scanf("%s", s[i] + 1);
        run(l, 3, n)
        {
            run(i, 1, n - l + 1)
            {
                int j;
                memset(tmp, 0, sizeof(tmp));
                strncpy(tmp + 1, s[1] + i, l);
                getkmp(tmp);
                for(j = 2; j <= m; j ++)
                    if(!Kmp(s[j]))
                        break;
                if(j > m)
                {
                    if(strlen(res + 1) > strlen(ans + 1))
                        strcpy(ans + 1, res + 1);
                    else if(strlen(res + 1) == strlen(ans + 1) && strcmp(ans + 1, res + 1) > 0)
                        strcpy(ans + 1, res + 1);
                }
            }
        }
        if(!strlen(ans + 1))
            printf("no significant commonalities\n");
        else
            printf("%s\n", ans + 1);
    }
}
