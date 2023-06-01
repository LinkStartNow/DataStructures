#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        int m = n / 2;
        for(int i = 0; i < m; i ++)
            for(int j = 0; j < m; j ++)
            {
                int t = matrix[n - 1 - j][i];
                matrix[n - 1  - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = t;
            }
        if(n % 2 == 1)
        {
            for(int i = 0; i < m; i ++)
            {
                int t = matrix[m][i];
                matrix[m][i] = matrix[n - 1 - i][m];
                matrix[n - 1 - i][m] = matrix[m][n - 1 - i];
                matrix[m][n - 1 - i] = matrix[i][m];
                matrix[i][m] = t;
            }
        }
    }
};
int main()
{
    Solution s;
    vector<vector<int>>q;
    for(int i = 0; i <3; i ++)
    {
        vector<int>t;
        for(int j = 0; j < 3; j ++)
        {
            int n;
            cin >> n;
            t.push_back(n);
        }
        q.push_back(t);
    }
    s.rotate(q);
}
