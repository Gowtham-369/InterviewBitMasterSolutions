bool valid(int i, int j, int n, int m)
{
    if (i >= 0 && i < n && j >= 0 && j < m)
    {
        return true;
    }
    return false;
}
int bfs(int src_x, int src_y, vector<vector<int>> &A, vector<vector<int>> &visited)
{
    int ans = 0;
    int n = A.size(), m = A[0].size();
    queue<pair<int, int>> q;
    q.push({src_x, src_y});
    visited[src_x][src_y] = 1;

    while (!q.empty())
    {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++)
        {
            pair<int, int> p = q.front();
            ans += 1;
            q.pop();
            int x = p.first, y = p.second;
            if (valid(x - 1, y, n, m) && visited[x - 1][y] == 0 && A[x - 1][y] == 1)
            {
                q.push({x - 1, y});
                visited[x - 1][y] = 1;
            }
            if (valid(x + 1, y, n, m) && visited[x + 1][y] == 0 && A[x + 1][y] == 1)
            {
                q.push({x + 1, y});
                visited[x + 1][y] = 1;
            }
            if (valid(x, y + 1, n, m) && visited[x][y + 1] == 0 && A[x][y + 1] == 1)
            {
                q.push({x, y + 1});
                visited[x][y + 1] = 1;
            }
            if (valid(x, y - 1, n, m) && visited[x][y - 1] == 0 && A[x][y - 1] == 1)
            {
                q.push({x, y - 1});
                visited[x][y - 1] = 1;
            }
            if (valid(x - 1, y - 1, n, m) && visited[x - 1][y - 1] == 0 && A[x - 1][y - 1] == 1)
            {
                q.push({x - 1, y - 1});
                visited[x - 1][y - 1] = 1;
            }
            if (valid(x + 1, y + 1, n, m) && visited[x + 1][y + 1] == 0 && A[x + 1][y + 1] == 1)
            {
                q.push({x + 1, y + 1});
                visited[x + 1][y + 1] = 1;
            }
            if (valid(x - 1, y + 1, n, m) && visited[x - 1][y + 1] == 0 && A[x - 1][y + 1] == 1)
            {
                q.push({x - 1, y + 1});
                visited[x - 1][y + 1] = 1;
            }
            if (valid(x + 1, y - 1, n, m) && visited[x + 1][y - 1] == 0 && A[x + 1][y - 1] == 1)
            {
                q.push({x + 1, y - 1});
                visited[x + 1][y - 1] = 1;
            }
        }
    }
    return ans;
}
int Solution::solve(vector<vector<int>> &A)
{

    int n = A.size();
    if (n == 0)
    {
        return 0;
    }
    int m = A[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == 0 && A[i][j] == 1)
            {
                //start_bfs from here
                //cover all connected components/neighbours
                int n_ones = bfs(i, j, A, visited);
                ans = max(ans, n_ones);
            }
            else
            {
                visited[i][j] = 1;
            }
        }
    }
    return ans;
}
