int dfs(int node, int par, int dest, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;
    if (node == dest)
    {
        return 1;
    }
    for (int it : adj[node])
    {
        if (!vis[it])
        {
            if (dfs(it, node, dest, vis, adj))
            {
                return 1;
            }
        }
    }
    return 0;
}
int Solution::solve(int A, vector<vector<int>> &B)
{
    vector<vector<int>> adj(A + 1);
    int m = B.size();
    vector<int> vis(A + 1, 0);
    for (int i = 0; i < m; i++)
    {
        adj[B[i][0]].push_back(B[i][1]); //directed
    }
    // for(int i=1; i<=A; i++){
    //     if(!vis[i]){
    //         if(dfs(i,-1,A,vis,adj)){
    //             return 1;
    //         }
    //     }
    // }
    if (!vis[1])
    {
        if (dfs(1, -1, A, vis, adj))
        {
            return 1;
        }
    }
    return 0;
}
