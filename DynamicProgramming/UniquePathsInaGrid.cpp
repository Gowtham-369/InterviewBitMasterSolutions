map<pair<int, int>, int> mp;
int n_ways(int i, int j, int n, int m, vector<vector<int>> &A)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (i == 0 and j == 0)
    {
        if (A[i][j] == 0)
            return 1;
        else
            return 0;
    }
    if (A[i][j] == 0)
    {
        // return n_ways(i-1,j,n,m,A)+n_ways(i,j-1,n,m,A);
        if (mp.find({i - 1, j}) == mp.end())
        {
            mp[{i - 1, j}] = n_ways(i - 1, j, n, m, A);
        }
        if (mp.find({i, j - 1}) == mp.end())
        {
            mp[{i, j - 1}] = n_ways(i, j - 1, n, m, A);
        }
        mp[{i, j}] = mp[{i, j - 1}] + mp[{i - 1, j}];
        return mp[{i, j}];
    }
    else
    {
        return mp[{i, j}] = 0;
    }
}
int Solution::uniquePathsWithObstacles(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    mp.clear();
    return n_ways(n - 1, m - 1, n, m, A);
}
