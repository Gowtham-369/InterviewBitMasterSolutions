void bfs(int s, int d, vector<pair<int, int>> adj[], vector<int> &dist)
{
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //minheap
    pq.push({0, s});
    while (!pq.empty())
    {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop(); //dont forget this
        for (auto it : adj[node])
        {
            if (dist[node] + it.second < dist[it.first])
            {
                dist[it.first] = dist[node] + it.second;
                pq.push(make_pair(dist[it.first], it.first));
            }
        }
    }
}
int Solution::solve(int A, vector<vector<int>> &B, int C, int D, vector<vector<int>> &E)
{

    vector<pair<int, int>> adj[A + 1];
    int m = B.size();
    for (int i = 0; i < m; i++)
    {
        adj[B[i][0]].push_back({B[i][1], B[i][2]});
        adj[B[i][1]].push_back(make_pair(B[i][0], B[i][2]));
    }
    vector<int> dist(A + 1, INT_MAX);
    bfs(C, D, adj, dist);
    int low = dist[D];
    for (int i = 0; i < (int)E.size(); i++)
    {
        adj[E[i][0]].push_back({E[i][1], E[i][2]});
        adj[E[i][1]].push_back(make_pair(E[i][0], E[i][2]));
        fill(dist.begin(), dist.end(), INT_MAX);
        bfs(C, D, adj, dist);
        low = min(low, dist[D]);
        adj[E[i][0]].pop_back();
        adj[E[i][1]].pop_back();
    }
    if (low == INT_MAX)
    {
        return -1;
    }
    else
    {
        return low;
    }
}
