bool isvalid(int x, int y, vector<vector<int>> &A)
{
    if (x >= 0 && x < (int)A.size() && y >= 0 && y < (int)A[x].size())
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Solution::solve(vector<vector<int>> &A)
{

    int n = A.size();
    if (n <= 0)
    {
        return -1;
    }
    int m = A[0].size();
    vector<vector<int>> t(n, vector<int>(m, 1));
    for (int i = 0; i < n; i++)
    {
        // int m = A[i].size();
        // t[i].resize(m,1);
        for (int j = 0; j < m; j++)
        {
            if (j - 1 >= 0 && A[i][j] > A[i][j - 1])
            {
                t[i][j] = max(t[i][j], 1 + t[i][j - 1]);
            }
            if (i - 1 >= 0 && A[i][j] > A[i - 1][j])
            {
                t[i][j] = max(t[i][j], 1 + t[i - 1][j]);
            }
        }
    }
    return (t[n - 1][m - 1] == n + m - 1 ? n + m - 1 : -1);

    /*
    int n = A.size();
    int m = A[0].size();
    queue<pair<int,int>> q;
    q.push({0,0});
    bool found = false;
    while(!q.empty()){
        int qsize = q.size();
        for(int i=0; i<qsize; i++){
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first,y = p.second;
            if(x == n-1 && y == m-1){
                found = true;
            }
            int x1 = x,y1 = y+1;
            if(isvalid(x1,y1,A) && A[x1][y1]>A[x][y]){
                q.push({x1,y1});
            }
            int x2 = x+1,y2 = y;
            if(isvalid(x2,y2,A) && A[x2][y2]>A[x][y]){
                q.push({x2,y2});
            }
        }
    }
    return (found?n+m-1:-1);
    */
}
