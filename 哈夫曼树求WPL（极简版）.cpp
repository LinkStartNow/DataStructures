#include<bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int main()
{
    int t, ans = 0;
    while(cin >> t) q.push(t);
    while(q.size() >= 2) // 除了根节点以外所有节点相加就是WPL
    {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        q.push(a + b), ans += a + b;
    }
    cout << ans << endl;
}
