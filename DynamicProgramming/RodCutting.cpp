/*
#define deb2(x,y) cout<<#x<<" "<<x<<#y<<" "<<y<<"\n"
pair<int,vector<int>> solve(int rod_start,int rod_end,int l,int r,vector<int> &B){
    if(l>r){
        vector<int> empty;
        return {0,empty};
    }
    int m = B.size();
    pair<int,vector<int>> ans;
    int min_cost = INT_MAX;
    for(int i=l; i<=r; i++){
        int cut_at = B[i];
        int cost = rod_end-rod_start;
        pair<int,vector<int>> res;
        pair<int,vector<int>> ans1 = solve(rod_start,cut_at,l,i-1,B);
        pair<int,vector<int>> ans2 = solve(cut_at,rod_end,i+1,r,B);
        int t_cost = cost+ans1.first+ans2.first;
        // deb2(t_cost,i);
        if(t_cost < min_cost){
            min_cost = t_cost;
            res.first = t_cost;
            res.second.push_back(cut_at);
            res.second.insert(res.second.end(),ans1.second.begin(),ans1.second.end());
            res.second.insert(res.second.end(),ans2.second.begin(),ans2.second.end());
            ans = res;
        }
    }
    return ans;
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    int m = B.size();
    int l = 0,r = m-1;
    int len = A;
    pair<int,vector<int>> p = solve(0,len,l,r,B);
    return p.second;
}
*/
/*
vector<int> helper(int start,int end,vector<int> &B,long long &cost,
                       map<pair<int,int>, pair<long long,vector<int>>> &dp)
{
   vector<int> ans;
   int m = B.size();
    if(dp.find({start,end}) != dp.end())
    {
        pair<long long,vector<int>> pi = dp[{start,end}];
        cost = pi.first;
        return pi.second;
    }
    if(B.size() == 1)
    {
        if(B[0] < start || end < B[0])
        {
            cost=0.0;
        }
        else
        {
            ans.push_back(B[0]);
            cost = end-start;
        }
        return ans;
   }
long long l,r;
long long ans1 = INT_MAX;
cost = LONG_MAX;
   vector<int> lans,rans;
   for(int i=0;i<m;i++)
   {
       vector<int> larr,rarr;
       if(B[i] < start || end < B[i])
         continue;
       int temp = B[i];
       B[i] = INT_MIN;
       rarr=helper(temp,end,B,r,dp);
       larr=helper(start,temp,B,l,dp);
       
       B[i] = temp;
       if(cost > l+r)
       {
          cost = l+r;
          ans1 = temp;
          ans.clear();
          lans = larr;
          rans = rarr;
       }
   }
    for(int i:rans)
        ans.push_back(i);
    for(int i:lans)
        ans.push_back(i);

   
    if(ans1 != INT_MAX)
        ans.push_back(ans1);
    cost = cost==LONG_MAX?0:cost+(end-start);
    dp[{start,end}] = {cost,ans};
    return ans;
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    long long cost =0;
    sort(B.begin(),B.end());
    map<pair<int,int>, pair<long long,vector<int>>> dp;
    vector<int> ans = helper(0,A,B,cost,dp);
    reverse(ans.begin(),ans.end());
    return ans;
}
*/
using ll = long long;
ll MinCost(int st, int end, vector<int> &cuts, vector<vector<ll>> &dp, vector<vector<int>> &cut)
{
    if (abs(end - st) <= 1)
        return 0;
    if (dp[st][end] != -1)
        return dp[st][end];
    ll ans = -1;
    for (int i = st + 1; i < end; i++)
    {
        ll a = cuts[end] - cuts[st] + MinCost(st, i, cuts, dp, cut) + MinCost(i, end, cuts, dp, cut);
        if ((ans == -1LL) || (ans > a))
        {
            cut[st][end] = i;
            ans = a;
        }
    }
    dp[st][end] = ans;
    return ans;
}

void Fill(vector<int> &ans, vector<vector<int>> &cut, vector<int> &cuts, int st, int end)
{
    if (abs(end - st) <= 1)
        return;
    ans.push_back(cuts[cut[st][end]]);
    Fill(ans, cut, cuts, st, cut[st][end]);
    Fill(ans, cut, cuts, cut[st][end], end);
}

vector<int> Solution::rodCut(int A, vector<int> &B)
{
    B.push_back(0);
    B.push_back(A);
    sort(B.begin(), B.end());
    int m = B.size();
    vector<vector<ll>> dp(m, vector<ll>(m, -1));
    vector<vector<int>> cut(m, vector<int>(m));
    MinCost(0, m - 1, B, dp, cut);
    vector<int> ans;
    Fill(ans, cut, B, 0, m - 1);
    return ans;
}
