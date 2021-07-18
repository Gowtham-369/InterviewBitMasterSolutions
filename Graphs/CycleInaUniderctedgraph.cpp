int cyclebfs(int src, int p, vector<int> &vis, vector<int> adj_list[])
{
    queue<pair<int, int>> q;
    q.push({src, p});
    vis[src] = 1;
    while (!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for (auto it : adj_list[node])
        {
            if (!vis[it])
            {
                q.push({it, node});
                vis[it] = 1;
            }
            else
            {
                if (it != par)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
int cycledfs(int node, int parent, vector<int> &vis, vector<int> adj_list[])
{
    vis[node] = 1;
    for (auto it : adj_list[node])
    {
        if (!vis[it])
        {
            if (cycledfs(it, node, vis, adj_list))
            {
                return 1;
            }
        }
        else
        {
            if (it != parent)
            {
                return 1;
            }
        }
    }
    return 0;
}
int Solution::solve(int A, vector<vector<int>> &B)
{
    vector<int> adj_list[A + 1];
    int m = B.size();
    for (int i = 0; i < m; i++)
    {
        adj_list[B[i][0]].push_back(B[i][1]);
        adj_list[B[i][1]].push_back(B[i][0]);
    }
    vector<int> vis(A + 1, 0);
    // for(int i=1; i<=A; i++){
    //     if(!vis[i]){
    //         if(cyclebfs(i,-1,vis,adj_list)){
    //             return 1;
    //         }
    //     }
    // }
    for (int i = 1; i <= A; i++)
    {
        if (!vis[i])
        {
            if (cycledfs(i, -1, vis, adj_list))
            {
                return 1;
            }
        }
    }
    return 0;
}
