#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[15];
struct Trie
{
    int trie[N][10], cnt = 0;
    bool Exit[N];
    void init()
    {
        memset(trie[0], 0, sizeof(trie[0]));
        for(int i = 0; i <= cnt; i ++)
        {
            Exit[i] = 0;
        }
        cnt = 0;
    }
    void build()
    {
        int l = strlen(s + 1), p = 0;
        for(int i = 1; i <= l; i ++)
        {
            int c = s[i] - '0';
            if(!trie[p][c])
            {
                trie[p][c] = ++ cnt;
                memset(trie[cnt], 0, sizeof(trie[cnt]));
            }
            p = trie[p][c];
        }
        Exit[p] = 1;
    }
    bool search()
    {
        int l = strlen(s + 1), p = 0;
        for(int i = 1; i < l; i ++)
        {
            int c = s[i] - '0';
            if(Exit[trie[p][c]])
                return 0;
            if(!trie[p][c])
                return 1;
            p = trie[p][c];
        }
        int c = s[l] - '0';
        if(trie[p][c] || Exit[trie[p][c]])
            return 0;
        else
            return 1;
    }
} trie;
int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        bool flag = true;
        trie.init();
        int n;
        scanf("%d", &n);
        while(n --)
        {
            scanf("%s", s + 1);
            if(!trie.search())
            {
                flag = false;
            }
            trie.build();
        }
        if(flag)
            puts("YES\n");
        else
            puts("NO\n");
    }
}
