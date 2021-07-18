// map<pair<int,int>,int> mp;
vector<vector<int>> t;
/*
int minsumpath(int i,int j,vector<vector<int>> &A){
    if(i == 0 and j == 0){
        return A[0][0];
    }
    if(i == 0){
        // return A[i][j]+minsumpath(i,j-1,A);
        if(mp.find({i,j-1}) == mp.end()){
            mp[{i,j-1}] = minsumpath(i,j-1,A);
        }
        mp[{i,j}] = A[i][j]+mp[{i,j-1}];
        return mp[{i,j}];
    }
    else if(j == 0){
        // return A[i][j]+minsumpath(i-1,j,A);
        if(mp.find({i-1,j}) == mp.end()){
            mp[{i-1,j}] = minsumpath(i-1,j,A);
        }
        mp[{i,j}] = A[i][j]+mp[{i-1,j}];
        return mp[{i,j}];
    }
    else{
        // return A[i][j]+min(minsumpath(i-1,j,A),minsumpath(i,j-1,A));
        if(mp.find({i-1,j}) == mp.end()){
            mp[{i-1,j}] = minsumpath(i-1,j,A);
        }
        if(mp.find({i,j-1}) == mp.end()){
            mp[{i,j-1}] = minsumpath(i,j-1,A);
        }
        mp[{i,j}] = A[i][j]+min(mp[{i-1,j}],mp[{i,j-1}]);
        return mp[{i,j}];
    }
}
*/
int minsumpath(int i, int j, vector<vector<int>> &A)
{
    if (i == 0 and j == 0)
    {
        return A[0][0];
    }
    if (i == 0)
    {
        // return A[i][j]+minsumpath(i,j-1,A);
        if (t[i][j - 1] == -1)
        {
            t[i][j - 1] = minsumpath(i, j - 1, A);
        }
        t[i][j] = A[i][j] + t[i][j - 1];
        return t[i][j];
    }
    else if (j == 0)
    {
        // return A[i][j]+minsumpath(i-1,j,A);
        if (t[i - 1][j] == -1)
        {
            t[i - 1][j] = minsumpath(i - 1, j, A);
        }
        t[i][j] = A[i][j] + t[i - 1][j];
        return t[i][j];
    }
    else
    {
        // return A[i][j]+min(minsumpath(i-1,j,A),minsumpath(i,j-1,A));
        if (t[i][j - 1] == -1)
        {
            t[i][j - 1] = minsumpath(i, j - 1, A);
        }

        if (t[i - 1][j] == -1)
        {
            t[i - 1][j] = minsumpath(i - 1, j, A);
        }
        t[i][j] = A[i][j] + min(t[i - 1][j], t[i][j - 1]);
        return t[i][j];
    }
}
int Solution::minPathSum(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();
    // mp.clear();
    t.erase(t.begin(), t.end());
    t.resize(n, vector<int>(m, -1));
    return minsumpath(n - 1, m - 1, A);
}
