#include <bits/stdc++.h>
using namespace std;
bool dfs(int node, int parent, vector<int> &color, vector<int> adj[])
{
    for(auto it:adj[node]){
        if(color[it] == -1){
            color[it] = 1-color[node];
            if(!dfs(it,node,color,adj)){
                false;
            }
        }
        else{
            if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}
bool checkBipartite(vector<int> adj[],int n){
    vector<int> color(n+1,-1);
    for(int i=0; i<=n; i++){
        if(color[i] == -1){
            color[i] = 1;
            if(!dfs(i,-1,color,adj)){
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (checkBipartite(adj, n))
    {
        cout << "yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}

/*
8 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 7 
1 7
4 5 

// bipartite graph example 
*/

/*
7 7 
0 1 
1 2 
2 3 
3 4 
4 6 
6 1
4 5 
// not bipartite example
*/