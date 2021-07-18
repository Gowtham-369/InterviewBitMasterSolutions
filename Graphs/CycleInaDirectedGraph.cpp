int cycledfs(int node, int parent, vector<int> &vis, vector<int> &dfsvis, vector<int> adj_list[])
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for (auto it : adj_list[node])
    {
        if (!vis[it])
        {
            if (cycledfs(it, node, vis, dfsvis, adj_list))
            {
                return 1;
            }
        }
        else
        {
            if (dfsvis[it] == 1)
            {
                return 1;
            }
        }
    }
    dfsvis[node] = 0;
    return 0;
}
int Solution::solve(int A, vector<vector<int>> &B)
{
    vector<int> adj_list[A + 1];
    int m = B.size();
    for (int i = 0; i < m; i++)
    {
        adj_list[B[i][0]].push_back(B[i][1]);
        // adj_list[B[i][1]].push_back(B[i][0]);
    }
    vector<int> vis(A + 1, 0);
    vector<int> dfsvis(A + 1, 0);
    for (int i = 1; i <= A; i++)
    {
        if (!vis[i])
        {
            if (cycledfs(i, -1, vis, dfsvis, adj_list))
            {
                return 1;
            }
        }
    }
    return 0;
}
