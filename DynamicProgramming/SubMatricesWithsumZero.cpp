int calc(vector<int> &temp)
{
    int n = temp.size();
    map<int, int> mp;
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        sum += temp[i];
        if (sum == 0)
        {
            cnt += 1;
        }
        if (mp.find(sum) != mp.end())
        {
            cnt += mp[sum];
            mp[sum] += 1;
        }
        else
        {
            mp[sum] = 1;
        }
    }
    return cnt;
}
int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size();
    if (n == 0)
    {
        return 0;
    }
    int m = A[0].size();
    int cnt = 0;
    //start from here
    /*
    vector<vector<int>> prs(n+1,vector<int>(m+1,0));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            prs[i][j] = prs[i][j-1]+prs[i-1][j]-prs[i-1][j-1]+A[i-1][j-1];
        }
    }
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int h = i,w = j;
            for(int p=1; p<=h; p++){
                for(int q=1; q<=w; q++){
                    int sum = prs[i][j]-prs[i][q-1]-prs[p-1][j]+prs[p-1][q-1];
                    if(sum == 0){
                        cnt += 1;
                    }
                }
            }
        }
    }
    return cnt;
    */
    //end here
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = i; j < m; j++)
        {
            for (int row = 0; row < n; row++)
            {
                temp[row] += A[row][j];
            }
            cnt += calc(temp);
        }
    }
    return cnt;
}
