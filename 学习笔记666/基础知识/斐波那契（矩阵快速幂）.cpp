#include<bits/stdc++.h>
using namespace std;
struct matrix
{
    int a[3][3];
    matrix()
    {
        memset(a,0,sizeof(a));
    }
    matrix operator*(const matrix &b)const
    {
        matrix res;
        for(int i = 1; i <= 2; i ++)
            for(int j = 1; j <= 2; j ++)
                for(int k = 1; k <= 2; k ++)
                    res.a[i][j] = res.a[i][j] + a[i][k]*b.a[k][j];
        return res;
    }
    void setx(int x)
    {
        for(int i = 1; i <= 2; i ++)
            a[i][i] = x;
    }
};
matrix spow(matrix x,int n)
{
    matrix ans;
    ans.setx(1);
    while(n > 0)
    {
        if(n & 1 == 1)
            ans = ans * x;
        x = x * x;
        n >>= 1;
    }
    return ans;
}
void solve()
{
    int n;
    cin >> n;
    matrix trains,f;
    f.a[1][1] = f.a[2][1] = 1;
    trains.a[1][1] = trains.a[2][1] = trains.a[1][2] = 1;
    trains = spow(trains,n - 2);
    f = trains * f;
    printf("%d\n",f.a[1][1]);
}
int main()
{
    int n;
    cin >> n;
    while(n --)
    {
        solve();
    }
}
