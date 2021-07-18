#include <bits/stdc++.h>
using namespace std;
class Solution{
    
    void dfs(int src,int par,stack<int> &st,vector<int> &vis,vector<int> adj[]){
        vis[src] = 1;
        for(auto it:adj[src]){
            if(!vis[it]){
                dfs(it,src,st,vis,adj);
            }
        }
        st.push(src);
    }
    public:
    vector<int> dfstopoSort(int N, vector<int> adj[])
    {
        vector<int> vis(N, 0);
        stack<int> st;
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, st, vis, adj);
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
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
                vector<int> res = obj.dfstopoSort(N, adj);

                cout << check(N, res, adj) << endl;
            }

            return 0;
        } // } Driver Code Ends