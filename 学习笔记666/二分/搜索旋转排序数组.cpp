#include<bits/stdc++.h>

//#define int __int128
#define run(i, a, b) for(int i = a; i <= b; i ++)
#define rep(i, a, b) for(int i = a; i >= b; i --)
#define x(i) x = i << 1
#define y(i) y = i << 1 | 1
#define m(l, r) m = (l + r) >> 1
//#define t() int t; cin >> t; while(t --)
#define ms(i) memset(i, 0, sizeof(i))
#define ll long long

using namespace std;
const int N = 3e3 + 7;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int l = 0, r = len - 1;
        while(l <= r)
        {
            int m = (l + r) >> 1;
            if(nums[m] == target)
                return m;
            if(nums[l] <= nums[m])
            {
                if(nums[m] > target && nums[l] <= target)
                    r = m - 1;
                else
                    l = m + 1;
            }
            else
            {
                if(target > nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return -1;
    }
}; //https://leetcode.cn/leetbook/read/binary-search/xeog5j/
void solve()
{

}
int main()
{
    solve();
    return 0;
}
