#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int bfstopoSort(int N, vector<int> adj[])
    {
        vector<int> Indegree(N, 0);
        for (int i = 0; i < N; i++)
        {
            for (int it : adj[i])
            {
                Indegree[it] += 1;
            }
        }
        deque<int> dq;
        for (int i = 0; i < N; i++)
        {
            if (Indegree[i] == 0)
            {
                dq.push_back(i);
            }
        }
        //do bfs
        // vector<int> topo;
        int cnt = 0;
        while (!dq.empty())
        {
            int node = dq.front();
            // topo.push_back(node);
            cnt += 1;
            dq.pop_front();
            for (int it : adj[node])
            {
                Indegree[it] -= 1;
                if (Indegree[it] == 0)
                {
                    dq.push_back(it);
                }
            }
        }
        // return topo;
        if(cnt == N){
            //no cycle
            return 0;
        }
        else{
            return 1;
        }
    }
};
/*
{
    Driver Code Starts.

        /*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector<int> &res, vector<int> adj[])
{
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        // vector<int> res = obj.bfstopoSort(N, adj);
        int res = obj.bfstopoSort(N, adj);
        // cout << check(N, res, adj) << endl;
        cout<<res<<endl;
    }

    return 0;
} // } Driver Code Ends