int dir_x[] = {0, 0, 1, -1};
int dir_y[] = {1, -1, 0, 0};
int isvalid(int i, int j, int n, int m)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        return 1;
    }
    return 0;
}
void bfs(int i, int j, int n, int m, vector<vector<int>> &vis, vector<string> &A)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int idx = 0; idx < 4; idx++)
        {
            if (isvalid(x + dir_x[idx], y + dir_y[idx], n, m) && A[x + dir_x[idx]][y + dir_y[idx]] == 'X' && vis[x + dir_x[idx]][y + dir_y[idx]] == 0)
            {
                vis[x + dir_x[idx]][y + dir_y[idx]] = 1;
                q.push({x + dir_x[idx], y + dir_y[idx]});
            }
        }
    }
}
void dfs(int i, int j, int n, int m, vector<vector<int>> &vis, vector<string> &A)
{
    vis[i][j] = 1;
    int x = i, y = j;
    for (int idx = 0; idx < 4; idx++)
    {
        if (isvalid(x + dir_x[idx], y + dir_y[idx], n, m) && A[x + dir_x[idx]][y + dir_y[idx]] == 'X' && vis[x + dir_x[idx]][y + dir_y[idx]] == 0)
        {
            dfs(x + dir_x[idx], y + dir_y[idx], n, m, vis, A);
        }
    }
}
int Solution::black(vector<string> &A)
{
    int n = A.size();
    if (n == 0)
    {
        return 0;
    }
    int m = A[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 'X' && vis[i][j] == 0)
            {
                cnt += 1;
                bfs(i, j, n, m, vis, A);
                // dfs(i,j,n,m,vis,A);
            }
        }
    }
    return cnt;
}
