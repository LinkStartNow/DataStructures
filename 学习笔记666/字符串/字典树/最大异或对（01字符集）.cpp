#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct Trie01
{
    int trie[32 * N][2], cnt;
    void putin(int n)
    {
        int p = 0;
        for(int i = 31; i >= 0; i --)
        {
            if((n >> i) & 1)
            {
                if(!trie[p][1])
                {
                    trie[p][1] = ++ cnt;
                    trie[cnt][0] = trie[cnt][1] = 0;
                }
                p = trie[p][1];
            }
            else
            {
                if(!trie[p][0])
                {
                    trie[p][0] = ++ cnt;
                    trie[cnt][0] = trie[cnt][1] = 0;
                }
                p = trie[p][0];
            }
        }
    }
    int sear(int n)
    {
        int p = 0, ans = 0;
        for(int i = 31; i >= 0; i --)
        {
            if(trie[p][((n >> i) & 1) ^ 1])
            {
                ans |= (1 << i);
                p = trie[p][((n >> i) & 1) ^ 1];
            }
            else
            {
                p = trie[p][((n >> i) & 1)];
            }
        }
        return ans;
    }
}trie;
int main()
{
    int n, t;
    int ans = 0;
    scanf("%d", &n);
    while(n --)
    {
        scanf("%d", &t);
        ans = max(ans, trie.sear(t));
        trie.putin(t);
    }
    printf("%d\n", ans);
}
