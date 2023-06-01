#include<bits/stdc++.h>

#define int __int128
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))
#define ll long long

using namespace std;

const int N = 25;
int dr, dl;
ll l, r, k;
ll a[N];

void dfs(int now, int mul, int tot, int lim, bool target){
    if(now > k){
        if(mul == 1)
            return;
        if(tot & 1)
            if(target)
                dr += lim / mul;
            else
                dl += lim / mul;
        else
            if(target)
                dr -= lim / mul;
            else
                dl -= lim / mul;
        return;
    }
    mul *= a[now];
    if(mul <= lim)
        dfs(now + 1, mul, tot + 1, lim, target);
    mul /= a[now];
    dfs(now + 1, mul, tot, lim, target);
}
signed main(){
    cin >> l >> r >> k;
    run(i, 1, k)
        cin >> a[i];
    dfs(1, 1, 0, r, 1), dfs(1, 1, 0, l - 1, 0);
    cout << (r - l + 1) - (ll)(dr - dl) << endl;

}
