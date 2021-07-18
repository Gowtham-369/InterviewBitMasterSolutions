/*
#define PII pair<int,pair<int,int>>

int X[]={-1,0,0,1};
int Y[]={0,1,-1,0};
int Solution::solve(int A, int B, vector<string> &C) {

vector<vector<int>>dist(A,vector<int>(B));
    vector<char> dir = {'U','R','L','D'};
    
    for(int i=0;i<A;++i)
        for(int j=0;j<B;++j)
          dist[i][j]=INT_MAX;
          
    dist[0][0]=0;
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({dist[0][0],{0,0}});
    int x,y;
    while(!q.empty()){
        
        x = q.top().second.first;
        y = q.top().second.second;
        q.pop();
        for(int i=0;i<4;++i){
            int newx=x+X[i];
            int newy=y+Y[i];
            int add=(C[x][y]==dir[i])?0:1;
            if(newx>=0&&newx<A&&newy>=0&&newy<B&&(dist[x][y]+add)<dist[newx][newy]){
                dist[newx][newy]=dist[x][y]+add;
                    q.push({dist[newx][newy],{newx,newy}});
            }
        }
    }
        
    return dist[A-1][B-1];
}
*/
int bfs(int c, int x, int y, int n, int m, vector<vector<int>> &vis, vector<string> &C)
{
    deque<vector<int>> dq;
    vector<int> src = {c, x, y};
    dq.push_front(src);
    while (!dq.empty())
    {
        int cost = dq.front()[0];
        int i = dq.front()[1];
        int j = dq.front()[2];
        vis[i][j] = 1;
        dq.pop_front();
        if (i == n - 1 && j == m - 1)
        {
            return cost;
        }
        if (i + 1 < n && vis[i + 1][j] == 0)
        {
            if (C[i][j] == 'D')
            {
                dq.push_front({cost, i + 1, j});
            }
            else
            {
                dq.push_back({cost + 1, i + 1, j});
            }
        }
        if (i - 1 >= 0 && vis[i - 1][j] == 0)
        {
            if (C[i][j] == 'U')
            {
                dq.push_front({cost, i - 1, j});
            }
            else
            {
                dq.push_back({cost + 1, i - 1, j});
            }
        }
        if (j + 1 < m && vis[i][j + 1] == 0)
        {
            if (C[i][j] == 'R')
            {
                dq.push_front({cost, i, j + 1});
            }
            else
            {
                dq.push_back({cost + 1, i, j + 1});
            }
        }
        if (j - 1 >= 0 && vis[i][j - 1] == 0)
        {
            if (C[i][j] == 'L')
            {
                dq.push_front({cost, i, j - 1});
            }
            else
            {
                dq.push_back({cost + 1, i, j - 1});
            }
        }
    }
    return -1;
}
int Solution::solve(int A, int B, vector<string> &C)
{
    vector<vector<int>> vis(A, vector<int>(B, 0));
    int ans = bfs(0, 0, 0, A, B, vis, C);
    return ans;
}
