#include <bits/stdc++.h>
using namespace std;
void BFS(int src,int par,vector<int> adj[]){
    vector<int> dist(n+1,INT_MAX);
    deque<int> dq;
    dq.push_back(src);
    dist[src] = 0;
    while(!dq.empty()){
        int node = dq.front();
        dq.pop_front();
        for(auto it:adj[node]){
            if(dist[node]+1 < dist[it]){
                dist[it] = dist[node]+1;
                dq.push_back(it);
            }
        }
    }
    for(int i=0; i<=n; i++){
        cout<<dist[i]<<" ";
    }
}