/*
bool valid(int i,int j,int x,int y,int n,int m,int r){
    if(i>=0 && i<n && j>=0 && j<m && ((x-i)*(x-i)+(y-j)*(y-j) <= r*r)){
        return true;
    }
    return false;
}
void bfs(int src_x,int src_y,vector<vector<int>> &vis,int r){
    int n = vis.size();
    int m = vis[0].size();
    queue<pair<int,int>> q;
    q.push({src_x,src_y});
    vis[src_x][src_y] = 1;//center point
    while(!q.empty()){
        int q_size = q.size();
        while(q_size > 0){
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            if(valid(x+1,y,src_x,src_y,n,m,r)){
                q.push({x+1,y});
                vis[x+1][y] = 1;
            }
            if(valid(x-1,y,src_x,src_y,n,m,r)){
                q.push({x-1,y});
                vis[x-1][y] = 1;
            }
            if(valid(x,y+1,src_x,src_y,n,m,r)){
                q.push({x,y+1});
                vis[x][y+1] = 1;
            }
            if(valid(x,y-1,src_x,src_y,n,m,r)){
                q.push({x,y-1});
                vis[x][y-1] = 1;
            }
            if(valid(x-1,y-1,src_x,src_y,n,m,r)){
                q.push({x-1,y-1});
                vis[x-1][y-1] = 1;
            }
            
            if(valid(x+1,y+1,src_x,src_y,n,m,r)){
                q.push({x+1,y+1});
                vis[x+1][y+1] = 1;
            }
            if(valid(x+1,y-1,src_x,src_y,n,m,r)){
                q.push({x+1,y-1});
                vis[x+1][y-1] = 1;
            }
            if(valid(x-1,y+1,src_x,src_y,n,m,r)){
                q.push({x-1,y+1});
                vis[x-1][y+1] = 1;
            }
            q_size -= 1;
        }
        
    }
}
bool isvalid(int i,int j,int n,int m){
    if(i>=0 && i<n && j>=0 && j<m){
        return true;
    }
    return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    
    vector<vector<int>> vis(A+1,vector<int>(B+1,0));
    int rad = D;
    // mark points that are in the circle in the given range
    // int n_c = E.size();
    int n_c = C;
    for(int i=0; i<n_c; i++){
        bfs(E[i],F[i],vis,rad);
    }
    int n = vis.size();
    int m = vis[0].size();
    //do bfs from (0,0) until reach (A,B);
    queue<pair<int,int>> q;
    if(vis[0][0] == 0){
        q.push({0,0});
        vis[0][0] = 1;
    }
    while(!q.empty()){
        int q_size = q.size();
        while(q_size > 0){
            pair<int,int> p = q.front();
            q.pop();
            int x = p.first;
            int y = p.second;
            if(x == A && y == B){
                return "YES";
            }
            if(isvalid(x+1,y,n,m) && vis[x+1][y] == 0){
                q.push({x+1,y});
                vis[x+1][y] = 1;
            }
            if(isvalid(x-1,y,n,m) && vis[x-1][y] == 0){
                q.push({x-1,y});
                vis[x-1][y] = 1;
            }
            if(isvalid(x,y+1,n,m) && vis[x][y+1] == 0){
                q.push({x,y+1});
                vis[x][y+1] = 1;
            }
            if(isvalid(x,y-1,n,m) && vis[x][y-1] == 0){
                q.push({x,y-1});
                vis[x][y-1] = 1;
            }
            if(isvalid(x-1,y-1,n,m) && vis[x-1][y-1] == 0){
                q.push({x-1,y-1});
                vis[x-1][y-1] = 1;
            }
            
            if(isvalid(x+1,y+1,n,m) && vis[x+1][y+1] == 0){
                q.push({x+1,y+1});
                vis[x+1][y+1] = 1;
            }
            if(isvalid(x+1,y-1,n,m) && vis[x+1][y-1] == 0){
                q.push({x+1,y-1});
                vis[x+1][y-1] = 1;
            }
            if(isvalid(x-1,y+1,n,m) && vis[x-1][y+1] == 0){
                q.push({x-1,y+1});
                vis[x-1][y+1] = 1;
            }
            q_size -= 1;
        }
        
    }
    return "NO";
}
*/
int r[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int c[8] = {0, 1, 1, 1, 0, -1, -1, -1};
bool incircle(vector<int> &xc, vector<int> &yc, int R, int i, int j)
{
    for (int k = 0; k < xc.size(); k++)
    {
        if ((xc[k] - i) * (xc[k] - i) + (yc[k] - j) * (yc[k] - j) <= R * R)
            return true;
    }
    return false;
}
string Solution::solve(int x, int y, int n, int R, vector<int> &xc, vector<int> &yc)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<int>> vis(105, vector<int>(105, 0));
    vis[0][0] = 1;
    int flag = 0;
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < 8; k++)
        {
            if (i + r[k] >= 0 and i + r[k] <= x and j + c[k] >= 0 and j + c[k] <= y and !vis[i + r[k]][j + c[k]] and !incircle(xc, yc, R, i + r[k], j + c[k]))
            {
                vis[i + r[k]][j + c[k]] = 1;
                if (i + r[k] == x and j + c[k] == y)
                {
                    flag = 1;
                    break;
                }
                q.push({i + r[k], j + c[k]});
            }
        }
        if (flag)
            break;
    }
    if (flag)
        return "YES";
    return "NO";
}
