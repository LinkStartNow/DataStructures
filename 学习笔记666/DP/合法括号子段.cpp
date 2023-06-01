#include<bits/stdc++.h>

#define ll long long
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
#define t() int t; cin >> t; while(t --)
//#define t(i) int t; cin >> t; run(i, 1, t)
#define ms(i) memset(i, 0, sizeof(i))
#define pss pair<int, int>
#define speed ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

const ll N = 2e6 + 7;
char s[N];
int p[N], d[N];

void solve()
{
    ll ans = 0;
    stack<int> st;
    cin >> s + 1;
    int l = strlen(s + 1);
    run(i, 1, l)
        p[i] = -1;
    run(i, 1, l)
    if(s[i] == '(')
        st.push(i);
    else if(!st.empty())
        p[st.top()] = i, st.pop();
    rep(i, l, 1)
    if(p[i] != -1)
        d[i] = d[p[i] + 1] + 1, ans += d[i];
    else
        d[i] = 0;
    cout << ans << '\n';
}

int main() // https://www.51nod.com/Challenge/Problem.html#problemId=1791
{
    speed
    t()
    solve();
    return 0;
}
