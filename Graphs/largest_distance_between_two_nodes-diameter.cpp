/*
int res = 0;
pair<int,int> dfs(int node,int par,vector<int> &vis,vector<int> adj[]){
    vis[node] = 1;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(0);
    pq.push(0);//intilally push these to cover bases
    for(int it:adj[node]){
        if(!vis[it]){
            pair<int,int> p = dfs(it,node,vis,adj);
            res = max(res,1+p.first+p.second);//include this as root in the path
            pq.push(1+max(p.first,p.second));
            if((int)pq.size() > 2){
                pq.pop();
            }
        }
    }
    
    int a = pq.top();
    pq.pop();
    int b = pq.top();
    pq.pop();
    return {a,b};
    
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> adj[n],vis(n,0);
    int root;
    for(int i=0; i<n; i++){
        if(A[i] == -1){
            root = i;
        }
        else{
            adj[i].push_back(A[i]);
            adj[A[i]].push_back(i);
        }
    }
    pair<int,int> p = dfs(root,-1,vis,adj);
    res = 0;
    res = max(res,1+p.first+p.second);//we want root in our path
    //res stoes no of nodes
    return res-1;
}
*/
void dfs1(int node,int par,int &root2,int cur_depth,int &max_depth,vector<int> &vis,vector<int> adj[]){
    vis[node] = 1;
    if(max_depth < cur_depth){
        root2 = node;
        max_depth = cur_depth;
    }
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs1(it,node,root2,cur_depth+1,max_depth,vis,adj);
        }
    }
    
}
int dfs2(int node,int par,vector<int> &vis,vector<int> adj[]){
    int ans = 0;
    vis[node] = 1;
    for(auto it:adj[node]){
        if(vis[it] == 0)
            ans = max(ans,1+dfs2(it,node,vis,adj));
    }
    return ans;
}
int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<int> adj[n];
    int root1;
    for(int i=0; i<n; i++){
        if(A[i] == -1){
            root1 = i;
        }
        else{
            adj[i].push_back(A[i]);
            adj[A[i]].push_back(i);
        }
    }
    vector<int> vis(n+1,0);
    int root2 = root1;
    int cur_depth=0,max_depth = 0;
    dfs1(root1,-1,root2,cur_depth,max_depth,vis,adj);
    fill(vis.begin(),vis.end(),0);
    int ans = dfs2(root2,-1,vis,adj);
    return ans;
}

