#include <bits/stdc++.h>
using namespace std;
class Solution {

public:
    void topoDfs(int s, int V, vector<int> adj[], vector<int>& vis,stack<int> &st)
    {
        vis[s] = 1;
        for(auto it:adj[s]){
            if(!vis[it.first]){
                topoDfs(it.first,V,adj,vis,st);
            }
        }
        st.push(s);
    }
    public:
        void shortestPath(int V, vector<int>adj[]){
            vector<int> vis(V, 0); 
            stack<int> st;
            for(int i = 0;i<V;i++) {
                if(!vis[i]) {
                    topoDfs(i, V, adj, vis,st);
                }
            }
            vector<int> dist(V,INT_MAX);
            dist[0] = 0;
            while(!st.empty()){
                int node = st.top();
                st.pop();
                if(dist[node] != INT_MAX){
                    for(auto it:adj[node]){
                        if(dist[node]+it.second<dist[it.first]){
                            dist[it.first] = dist[node]+it.second;
                        }
                    }
                }
            }
            
            for(int i=0; i<V; i++){
                if(dist[i] == INT_MAX){
                    cout<<"INF ";
                }
                else{
                    cout<<dist[i]<<" ";
                }
            }
        }
};
// / { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<pair<int,int>> adj[V];
		for(int i = 0; i < E; i++){
			int u, v, w;
			cin >> u >> v>>w;
			adj[u].push_back({v,w});
		}
		Solution obj;
		obj.shortestPath(V,adj);
	}
	return 0;
}  // } Driver Code Ends