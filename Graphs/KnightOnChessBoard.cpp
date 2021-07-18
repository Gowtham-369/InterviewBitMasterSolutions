/*
int dx[8] = {2,1,-1,-2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};

int valid(int i,int j,int n,int m){
    if(i>0 && i<=n && j>0 && j<=m){
        return 1;
    }
    return 0;
}
void bfs(int i,int j,int n,int m,vector<vector<int>> &dist){
    queue<pair<int,int>> q;
    q.push({i,j});
    dist[i][j] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        //////////////////////////////////////////////////////////
        // int dx[] = {-1,1};
        // int dy[] = {-2,2};
        // for(int idx_1=0; idx_1<2; idx_1++){
        //     for(int idx_2=0; idx_2<2; idx_2++){
        //         if(valid(x+dx[idx_1],y+dy[idx_2],n,m)){
        //             if(dist[x][y]+1 < dist[x+dx[idx_1]][y+dy[idx_2]]){
        //                 dist[x+dx[idx_1]][y+dy[idx_2]] = dist[x][y]+1;
        //                 q.push({x+dx[idx_1],y+dy[idx_2]});
        //             }
        //         }
        //     }
        // }
        // dx[0] = -2;dx[1] = 2;
        // dy[0] = -1;dy[1] = 1;
        // for(int idx_1=0; idx_1<2; idx_1++){
        //     for(int idx_2=0; idx_2<2; idx_2++){
        //         if(valid(x+dx[idx_1],y+dy[idx_2],n,m)){
        //             if(dist[x][y]+1 < dist[x+dx[idx_1]][y+dy[idx_2]]){
        //                 dist[x+dx[idx_1]][y+dy[idx_2]] = dist[x][y]+1;
        //                 q.push(make_pair(x+dx[idx_1],y+dy[idx_2]));
        //             }
        //         }
        //     }
        // }
        //////////////////////////////////////////////////////////
        for(int idx=0; idx<8; idx++){
            
            if(valid(x+dx[idx],y+dy[idx],n,m)){
                if(dist[x][y]+1 < dist[x+dx[idx]][y+dy[idx]]){
                    dist[x+dx[idx]][y+dy[idx]] = dist[x][y]+1;
                    q.push({x+dx[idx],y+dy[idx]});
                }
            }
            
        }
    }
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    vector<vector<int>> dist(A+1,vector<int>(B+1,INT_MAX));
    bfs(C,D,A+1,B+1,dist);
    if(dist[E][F] == INT_MAX){
        return -1;
    }
    else{
        return dist[E][F];
    }
    
    
}
*/
bool check(int i, int j, int A, int B)
{
    return (i < A && i >= 0 && j < B && j >= 0);
}
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}; // the eight moves of knight in dx and dy together
int dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
map<pair<int, int>, int> vis;
int Solution::knight(int A, int B, int C, int D, int E, int F)
{
    vis.clear();
    C--, D--, E--, F--;
    if (C == E && D == F)
        return 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {C, D}});
    while (!q.empty())
    { // bfs for all possible moves
        int i = q.front().second.first, j = q.front().second.second;
        int lev = q.front().first;
        q.pop();
        for (int k = 0; k < 8; k++)
        {
            int x = i + dx[k], y = j + dy[k];
            if (check(x, y, A, B) && vis[{x, y}] == 0)
            {
                if (x == E && y == F)
                    return lev + 1;
                vis[{x, y}] = 1;
                q.push({lev + 1, {x, y}});
            }
        }
    }
    return -1;
}
