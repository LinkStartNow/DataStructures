#include<bits/stdc++.h>
using namespace std;
vector<int>v;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0,r = n - 1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l;
    }
};
int main()
{

}
