#include<bits/stdc++.h>

//#define int __int128
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))
#define ll long long

using namespace std;
int n;
struct fen
{
    int son, mom;
    fen()
    {
        mom = 1;
    }
    void Simplify()
    {
        int t = __gcd(son, mom);
        son /= t;
        mom /= t;
    }
    fen operator + (const fen &b) const
    {
        fen ans;
        int t = __gcd(mom, b.mom);
        t = mom * b.mom / t;
        ans.son = son * (t / mom) + b.son * (t / b.mom);
        ans.mom = t;
        ans.Simplify();
        return ans;
    }
    fen operator - (const fen &b) const
    {
        fen ans;
        int t = __gcd(mom, b.mom);
        t = mom * b.mom / t;
        ans.son = son * (t / mom) - b.son * (t / b.mom);
        ans.mom = t;
        ans.Simplify();
        return ans;
    }
    fen operator * (const fen &b) const
    {
        fen ans;
        ans.son = son * b.son;
        ans.mom = mom * b.mom;
        ans.Simplify();
        return ans;
    }
    fen operator / (const fen &b) const
    {
        fen ans;
        ans.son = son * b.mom;
        ans.mom = mom * b.son;
        ans.Simplify();
        return ans;
    }
    void print()
    {
        int t = __gcd(son, mom);
        son /= t;
        mom /= t;
        if(mom == 1)
            printf("%d", son);
        else
            printf("%d/%d", son, mom);
    }
    bool operator <(const fen &b) const
    {
        double p = son / mom;
        double q = b.son / b.mom;
        if(fabs(p) < fabs(q))
            return 1;
        else
            return 0;
    }
    void scan()
    {
        int t;
        scanf("%d", &t);
        son = t;
        mom = 1;
    }
} a[20][20];
void yyds()
{
    int r, c;
    int flag = 1;
    for(r = 1, c = 1; r < n && c <= n; c ++)
    {
        int p = r;
        run(i, r + 1, n)
        if(a[p][c] < a[i][c])
            p = i;
        if(r != p)
        {
            run(i, c, n)
            swap(a[p][i], a[r][i]);
            flag = 1 - flag;
        }
        if(a[r][c].son == 0)
        {
            r ++;
            continue;
        }
        run(i, r + 1, n)
        {
            fen k = a[i][c] / a[r][c];
            rep(j, n, c)
            a[i][j] = a[i][j] - a[r][j] * k;
        }
        r ++;
    }
    fen ans;
    ans.son = 1;
    run(i, 1, n)
    ans = ans * a[i][i];
    if(!flag)
        ans.son = -ans.son;
    printf("答案为：");
    ans.print();
    puts("");
}
int main()
{
    printf("输入任意字符开始:\n");
    getchar();
    printf("请输入矩阵阶数：");
    while(scanf("%d", &n) != EOF)
    {
        if(!n)
            break;
        printf("阶数读入成功，请输入数据:\n");
        run(i, 1, n)
        run(j, 1, n)
        a[i][j].scan();
        yyds();
        printf("请输入矩阵阶数：");
    }



//    a[1][1].print();
//    puts("");
//    a[1][2].print();
//    puts("");
//    if(a[1][1] < a[1][2])
//        puts("yes");
//    else
//        puts("no");
//    run(i, 1, n)
//    {
//        run(j, 1, n)
//        {
//            a[i][j].print();
//            printf(" ");
//        }
//        puts("");
//    }


}
