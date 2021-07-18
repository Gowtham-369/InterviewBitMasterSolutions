int cycledfs(int node, int par, vector<int> &vis, vector<int> &dfsvis, vector<int> adj[])
{
    vis[node] = 1;
    dfsvis[node] = 1;
    for (int it : adj[node])
    {
        if (!vis[it])
        {
            if (cycledfs(it, node, vis, dfsvis, adj))
            {
                return 1;
            }
        }
        else
        {
            if (dfsvis[it] == 1)
            {
                //cycle
                return 1;
            }
        }
    }
    dfsvis[node] = 0;
    return 0; //
}
int dfsUtil(int A, vector<int> adj[])
{
    vector<int> vis(A + 1, 0), dfsvis(A + 1, 0);
    for (int i = 1; i <= A; i++)
    {
        if (!vis[i])
        {
            if (cycledfs(i, -1, vis, dfsvis, adj))
            {
                return 1;
            }
        }
    }
    return 0;
}
int Solution::solve(int A, vector<int> &B, vector<int> &C)
{
    vector<int> adj[A + 1];
    int n = B.size();
    for (int i = 0; i < n; i++)
    {
        adj[B[i]].push_back(C[i]); //directed graph
    }
    int has_cycle = dfsUtil(A, adj);
    if (has_cycle)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
